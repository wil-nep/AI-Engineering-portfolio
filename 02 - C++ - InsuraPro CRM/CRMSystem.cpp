#include "CRMSystem.h"
#include <iostream>
#include <algorithm>

using namespace std;

/* 
* Aggiungi un cliente.
*/
void CRMSystem::addClient(const Client& client) {
    clients.push_back(client);
}

/* 
* Ottieni la lista dei clienti.
*/
const vector<Client>& CRMSystem::getClients() const {
    return clients;
}

/* 
* Rimuovi tutti i clienti.
*/
void CRMSystem::clearClients() {
    clients.clear();
}

/* 
* Trova un cliente per ID.
*/
Client* CRMSystem::findClientById(int id) {
    for (auto& client : clients) {
        if (client.getId() == id) {
            return &client;
        }
    }
    return nullptr;
}

/* 
* Trova un cliente per nome.
*/
vector<Client*> CRMSystem::findClientsByName(const string& firstName) {
    vector<Client*> matches;
    for (auto& client : clients) {
        if (client.getFirstName() == firstName) {
            matches.push_back(&client);
        }
    }
    return matches;
}

/* 
* Trova un cliente per cognome.
*/
vector<Client*> CRMSystem::findClientsBySurname(const string& lastName) {
    vector<Client*> matches;
    for (auto& client : clients) {
        if (client.getLastName() == lastName) {
            matches.push_back(&client);
        }
    }
    return matches;
}

/* 
* Stampa la lista dei clienti.
*/
void CRMSystem::printClientList(const vector<Client*>& matches) const {
    if (matches.empty()) {
        cout << "Nessun cliente trovato.\n";
    } else {
        for (size_t i = 0; i < matches.size(); ++i) {
            cout << i + 1 << ". ";
            matches[i]->printDetails();
            cout << "\n";
        }
    }
}

/* 
* Modifica un cliente chiedendo prima se cercarlo per ID, nome o cognome.
*/
void CRMSystem::editClient() {
    cout << "Come vuoi cercare il cliente da modificare?\n";
    cout << "1. Cerca per ID\n";
    cout << "2. Cerca per Nome\n";
    cout << "3. Cerca per Cognome\n";
    int searchChoice;
    cin >> searchChoice;

    Client* client = nullptr;

    switch (searchChoice) {
        case 1: {
            int id;
            cout << "Inserisci ID cliente: ";
            cin >> id;
            client = findClientById(id);
            break;
        }
        case 2: {
            string firstName;
            cout << "Inserisci Nome cliente: ";
            cin >> firstName;
            auto matches = findClientsByName(firstName);
            printClientList(matches);
            if (!matches.empty()) {
                int index;
                cout << "Seleziona il cliente (numero): ";
                cin >> index;
                if (index > 0 && index <= matches.size()) {
                    client = matches[index - 1];
                }
            }
            break;
        }
        case 3: {
            string lastName;
            cout << "Inserisci Cognome cliente: ";
            cin >> lastName;
            auto matches = findClientsBySurname(lastName);
            printClientList(matches);
            if (!matches.empty()) {
                int index;
                cout << "Seleziona il cliente (numero): ";
                cin >> index;
                if (index > 0 && index <= matches.size()) {
                    client = matches[index - 1];
                }
            }
            break;
        }
        default: {
            cout << "Opzione non valida.\n";
            return;
        }
    }

    if (!client) {
        cout << "Cliente non trovato.\n";
        return;
    }

    cout << "Quale campo vuoi modificare?\n";
    cout << "1. Nome\n";
    cout << "2. Cognome\n";
    cout << "3. Numero di telefono\n";
    cout << "4. Email\n";
    int fieldChoice;
    cin >> fieldChoice;

    switch (fieldChoice) {
        case 1: {
            string newFirstName;
            cout << "Inserisci nuovo Nome: ";
            cin >> newFirstName;
            if (!Client::isValidName(newFirstName)) {
                cout << "Errore: Nome non valido. Deve contenere solo lettere.\n";
                break;
            }
            client->setFirstName(newFirstName);
            cout << "Nome modificato con successo.\n";
            break;
        }
        case 2: {
            string newLastName;
            cout << "Inserisci nuovo Cognome: ";
            cin >> newLastName;
            if (!Client::isValidName(newLastName)) {
                cout << "Errore: Cognome non valido. Deve contenere solo lettere.\n";
                break;
            }
            client->setLastName(newLastName);
            cout << "Cognome modificato con successo.\n";
            break;
        }
        case 3: {
            string newPhone;
            cout << "Inserisci nuovo Numero di telefono: ";
            cin >> newPhone;
            if (!Client::isValidPhone(newPhone)) {
                cout << "Errore: Numero di telefono non valido.\n";
                break;
            }
            client->setPhone(newPhone);
            cout << "Numero di telefono modificato con successo.\n";
            break;
        }
        case 4: {
            string newEmail;
            cout << "Inserisci nuova Email: ";
            cin >> newEmail;
            if (!Client::isValidEmail(newEmail)) {
                cout << "Errore: Email non valida.\n";
                break;
            }
            client->setEmail(newEmail);
            cout << "Email modificata con successo.\n";
            break;
        }
        default: {
            cout << "Errore: Opzione non valida.\n";
            break;
        }
    }
}

/* 
* Rimuove un cliente chiedendo prima se cercarlo per ID, nome o cognome.
*/
void CRMSystem::removeClient() {
    cout << "Come vuoi cercare il cliente da rimuovere?\n";
    cout << "1. Cerca per ID\n";
    cout << "2. Cerca per Nome\n";
    cout << "3. Cerca per Cognome\n";
    int searchChoice;
    cin >> searchChoice;

    Client* client = nullptr;

    switch (searchChoice) {
        case 1: {
            int id;
            cout << "Inserisci ID cliente: ";
            cin >> id;
            client = findClientById(id);
            break;
        }
        case 2: {
            string firstName;
            cout << "Inserisci Nome cliente: ";
            cin >> firstName;
            auto matches = findClientsByName(firstName);
            printClientList(matches);
            if (!matches.empty()) {
                int index;
                cout << "Seleziona il cliente (numero): ";
                cin >> index;
                if (index > 0 && index <= matches.size()) {
                    client = matches[index - 1];
                }
            }
            break;
        }
        case 3: {
            string lastName;
            cout << "Inserisci Cognome cliente: ";
            cin >> lastName;
            auto matches = findClientsBySurname(lastName);
            printClientList(matches);
            if (!matches.empty()) {
                int index;
                cout << "Seleziona il cliente (numero): ";
                cin >> index;
                if (index > 0 && index <= matches.size()) {
                    client = matches[index - 1];
                }
            }
            break;
        }
        default: {
            cout << "Opzione non valida.\n";
            return;
        }
    }

    if (!client) {
        cout << "Cliente non trovato.\n";
        return;
    }

    auto it = remove_if(clients.begin(), clients.end(),
                        [client](const Client& c) { return c.getId() == client->getId(); });
    if (it != clients.end()) {
        clients.erase(it, clients.end());
        cout << "Cliente rimosso con successo.\n";
    } else {
        cout << "Errore durante la rimozione del cliente.\n";
    }
}

/* 
 * Visualizza la lista dei clienti.
*/
void CRMSystem::viewClients() const {
    if (clients.empty()) {
        cout << "Nessun cliente presente.\n";
    } else {
        for (const auto& client : clients) {
            client.printDetails();
            cout << "\n";
        }
    }
}

/* 
* Gestisce le interazioni di un cliente con l'azienda.
* Permette di cercare un cliente per ID, nome o cognome e gestire le interazioni.
* Permette di aggiungere un contratto o un appuntamento, visualizzare, modificare o eliminare le interazioni.
*/
void CRMSystem::manageClientInteractions() {
    cout << "Gestione interazioni cliente:\n";
    cout << "1. Cerca cliente per ID\n";
    cout << "2. Cerca cliente per Nome\n";
    cout << "3. Cerca cliente per Cognome\n";
    int searchChoice;
    cin >> searchChoice;

    Client* client = nullptr;

    switch (searchChoice) {
        case 1: {
            int id;
            cout << "Inserisci ID cliente: ";
            cin >> id;
            client = findClientById(id);
            break;
        }
        case 2: {
            string firstName;
            cout << "Inserisci Nome cliente: ";
            cin >> firstName;
            auto matches = findClientsByName(firstName);
            printClientList(matches);
            if (!matches.empty()) {
                int index;
                cout << "Seleziona il cliente (numero): ";
                cin >> index;
                if (index > 0 && index <= matches.size()) {
                    client = matches[index - 1];
                }
            }
            break;
        }
        case 3: {
            string lastName;
            cout << "Inserisci Cognome cliente: ";
            cin >> lastName;
            auto matches = findClientsBySurname(lastName);
            printClientList(matches);
            if (!matches.empty()) {
                int index;
                cout << "Seleziona il cliente (numero): ";
                cin >> index;
                if (index > 0 && index <= matches.size()) {
                    client = matches[index - 1];
                }
            }
            break;
        }
        default: {
            cout << "Opzione non valida.\n";
            return;
        }
    }

    if (!client) {
        cout << "Cliente non trovato.\n";
        return;
    }

    cout << "Gestione interazioni per il cliente: ID: " << client->getId()
         << ", Nome: " << client->getFirstName()
         << ", Cognome: " << client->getLastName() << endl;

    cout << "1. Aggiungi interazione\n";
    cout << "2. Visualizza interazioni\n";
    cout << "3. Modifica interazione\n";
    cout << "4. Rimuovi interazione\n";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            string type, date, time, details;
            cout << "Che tipo di interazione vuoi aggiungere?\n";
            cout << "1. Contratto\n";
            cout << "2. Appuntamento\n";
            int typeChoice;
            cin >> typeChoice;

            if (typeChoice == 1) {
                type = "CONTRATTO";
                cout << "Inserisci data (YYYY-MM-DD): ";
                cin >> date;
                cout << "Inserisci dettagli: ";
                cin.ignore();
                getline(cin, details);
                client->addInteraction(Interaction(type, date, details));
            } else if (typeChoice == 2) {
                type = "APPUNTAMENTO";
                cout << "Inserisci data (YYYY-MM-DD): ";
                cin >> date;
                cout << "Inserisci orario (HH:MM): ";
                cin >> time;
                cout << "Inserisci dettagli: ";
                cin.ignore();
                getline(cin, details);
                client->addInteraction(Interaction(type, date, details, time));
            } else {
                cout << "Scelta non valida.\n";
            }
            break;
        }
        case 2: {
            auto& interactions = client->getInteractions();
            if (interactions.empty()) {
                cout << "Nessuna interazione trovata.\n";
            } else {
                cout << "Interazioni:\n";
                for (size_t i = 0; i < interactions.size(); ++i) {
                    interactions[i].print();
                }
            }
            break;
        }
        case 3: {
            cout << "Che tipo di interazione vuoi modificare?\n";
            cout << "1. Contratto\n";
            cout << "2. Appuntamento\n";
            int typeChoice;
            cin >> typeChoice;

            auto& interactions = const_cast<vector<Interaction>&>(client->getInteractions());
            vector<size_t> filteredIndices;

            for (size_t i = 0; i < interactions.size(); ++i) {
                if ((typeChoice == 1 && interactions[i].getType() == "CONTRATTO") ||
                    (typeChoice == 2 && interactions[i].getType() == "APPUNTAMENTO")) {
                    filteredIndices.push_back(i);
                }
            }

            if (filteredIndices.empty()) {
                cout << "Nessuna interazione trovata.\n";
            } else {
                cout << "Interazioni disponibili:\n";
                for (size_t i = 0; i < filteredIndices.size(); ++i) {
                    cout << i + 1 << ". ";
                    interactions[filteredIndices[i]].print();
                }

                size_t index;
                cout << "Inserisci il numero dell'interazione da modificare: ";
                cin >> index;

                if (cin.fail() || index <= 0 || index > filteredIndices.size()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Indice non valido.\n";
                } else {
                    Interaction& interaction = interactions[filteredIndices[index - 1]];
                    cout << "Dettagli attuali: ";
                    interaction.print();
                    cout << "Inserisci nuovi dettagli: ";
                    cin.ignore();
                    string newDetails;
                    getline(cin, newDetails);
                    interaction.setDetails(newDetails);
                    cout << "Interazione modificata con successo.\n";
                }
            }
            break;
        }
        case 4: {
            cout << "Che tipo di interazione vuoi rimuovere?\n";
            cout << "1. Contratto\n";
            cout << "2. Appuntamento\n";
            int typeChoice;
            cin >> typeChoice;

            auto& interactions = const_cast<vector<Interaction>&>(client->getInteractions());
            vector<size_t> filteredIndices;

            for (size_t i = 0; i < interactions.size(); ++i) {
                if ((typeChoice == 1 && interactions[i].getType() == "CONTRATTO") ||
                    (typeChoice == 2 && interactions[i].getType() == "APPUNTAMENTO")) {
                    filteredIndices.push_back(i);
                }
            }

            if (filteredIndices.empty()) {
                cout << "Nessuna interazione trovata.\n";
            } else {
                cout << "Interazioni disponibili:\n";
                for (size_t i = 0; i < filteredIndices.size(); ++i) {
                    cout << i + 1 << ". ";
                    interactions[filteredIndices[i]].print();
                }

                size_t index;
                cout << "Inserisci il numero dell'interazione da rimuovere: ";
                cin >> index;

                if (index > 0 && index <= filteredIndices.size()) {
                    interactions.erase(interactions.begin() + filteredIndices[index - 1]);
                    cout << "Interazione rimossa con successo.\n";
                } else {
                    cout << "Indice non valido.\n";
                }
            }
            break;
        }
        default: {
            cout << "Opzione non valida.\n";
            break;
        }
    }
}