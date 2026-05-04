#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

/* 
 * Carica i dati del sistema CRM da un file.
 * Legge i clienti e le loro interazioni dal file specificato.
 */
bool FileManager::load(CRMSystem& crm, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile aprire il file per la lettura.\n";
        return false;
    }

    crm.clearClients();

    std::string line;
    const Client* currentClient = nullptr;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string firstField;
        std::getline(ss, firstField, ',');

        if (firstField == "CONTRATTO" || firstField == "APPUNTAMENTO") {
            std::string type = firstField;
            std::string date, time, details;

            std::getline(ss, date, ',');
            if (type == "APPUNTAMENTO") {
                std::getline(ss, time, ',');
            }
            std::getline(ss, details, ',');

            if (currentClient) {
                if (type == "CONTRATTO") {
                    const_cast<Client*>(currentClient)->addInteraction(Interaction(type, date, details));
                } else if (type == "APPUNTAMENTO") {
                    const_cast<Client*>(currentClient)->addInteraction(Interaction(type, date, details, time));
                }
            }
        } else {
            
            std::string id = firstField;
            std::string firstName, lastName, phone, email;
            std::getline(ss, firstName, ',');
            std::getline(ss, lastName, ',');
            std::getline(ss, phone, ',');
            std::getline(ss, email, ',');

            try {
                if (id.empty() || !std::all_of(id.begin(), id.end(), ::isdigit)) {
                    throw std::invalid_argument("ID non valido");
                }
                int clientId = std::stoi(id); 
                Client client(clientId, firstName, lastName, phone, email);
                crm.addClient(client);
                currentClient = &crm.getClients().back(); 
            } catch (const std::invalid_argument& e) {
                std::cerr << "Errore: ID cliente non valido nel file.\n";
                continue;
            }
        }
    }

    file.close();
    return true;
}

/* 
 * Salva i dati del sistema CRM in un file.
 * Scrive i clienti e le loro interazioni nel file specificato.
 */
bool FileManager::save(const CRMSystem& crm, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Errore: impossibile aprire il file per la scrittura.\n";
        return false;
    }


    for (const auto& client : crm.getClients()) {
        file << client.getId() << ","
             << client.getFirstName() << ","
             << client.getLastName() << ","
             << client.getPhone() << ","
             << client.getEmail() << "\n";

       
        for (const auto& interaction : client.getInteractions()) {
            if (interaction.getType() == "CONTRATTO") {
                file << "CONTRATTO," << interaction.getDate() << "," << interaction.getDetails() << "\n";
            } else if (interaction.getType() == "APPUNTAMENTO") {
                file << "APPUNTAMENTO," << interaction.getDate() << "," << interaction.getTime() << "," << interaction.getDetails() << "\n";
            }
        }
    }

    file.close();
    std::cout << "Dati salvati con successo nel file: " << filename << "\n";
    return true;
}