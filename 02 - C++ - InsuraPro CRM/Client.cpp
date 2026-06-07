#include "Client.h"
#include <iostream>
#include <regex>
#include <algorithm>

using namespace std;

/* 
 * Costruttore della classe Client.
 * Inizializza un cliente con ID, nome, cognome, numero di telefono e email.
 */
Client::Client(int id, const std::string& firstName, const std::string& lastName, const std::string& phone, const std::string& email)
    : id(id), firstName(firstName), lastName(lastName), phone(phone), email(email) {}

/* 
 * Getter per ottenere i dettagli del cliente.
 * Include ID, nome, cognome, numero di telefono, email e interazioni.
 */
int Client::getId() const { return id; }
const std::string& Client::getFirstName() const { return firstName; }
const std::string& Client::getLastName() const { return lastName; }
const std::string& Client::getPhone() const { return phone; }
const std::string& Client::getEmail() const { return email; }
const std::vector<Interaction>& Client::getInteractions() const { return interactions; }

/* 
 * Setter per aggiornare i dettagli del cliente.
 * Permette di modificare ID, nome, cognome, numero di telefono e email.
 */
void Client::setId(int newId) { id = newId; }
void Client::setFirstName(const std::string& newFirstName) { firstName = newFirstName; }
void Client::setLastName(const std::string& newLastName) { lastName = newLastName; }
void Client::setPhone(const std::string& newPhone) { phone = newPhone; }
void Client::setEmail(const std::string& newEmail) { email = newEmail; }

/* 
 * Funzioni di validazione per verificare la correttezza dei campi.
 * Controlla ID, nome, numero di telefono e email.
 */
bool Client::isValidId(const std::string& id) {
    return std::all_of(id.begin(), id.end(), ::isdigit);
}

bool Client::isValidName(const std::string& name) {
    return std::regex_match(name, std::regex("^[a-zA-Z]+$"));
}

bool Client::isValidPhone(const std::string& phone) {
    return std::regex_match(phone, std::regex("^\\+?[0-9]+$"));
}

bool Client::isValidEmail(const std::string& email) {
    return std::regex_match(email, std::regex("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$"));
}

/* 
 * Gestione delle interazioni del cliente.
 * Permette di aggiungere interazioni e ordinarle per data.
 */
void Client::addInteraction(const Interaction& interaction) {
    interactions.push_back(interaction);
    sortInteractionsByDate();
}

void Client::sortInteractionsByDate() {
    std::sort(interactions.begin(), interactions.end(), [](const Interaction& a, const Interaction& b) {
        return a.getDate() < b.getDate();
    });
}

/* 
 * Stampa i dettagli del cliente.
 * Include ID, nome, cognome, numero di telefono, email e tutte le interazioni.
 */
void Client::printDetails() const {
    cout << "ID: " << id << ", Nome: " << firstName << ", Cognome: " << lastName << ", Telefono: " << phone << ", Email: " << email << "\n";
    cout << "Interazioni:\n";
    for (const auto& interaction : interactions) {
        interaction.print();
    }
}