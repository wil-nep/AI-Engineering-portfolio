#include "CRMSystem.h"
#include "FileManager.h"
#include <iostream>

using namespace std;

/* 
 * Funzione principale del programma.
 * Gestisce il menu principale e le operazioni del sistema CRM.
 */
int main() {
    CRMSystem crm; 
    string filename = "data.txt"; 
    int choice; 
    do {
        cout << "\n=== CRM InsuraPro ===\n";
        cout << "1. Aggiungi cliente\n";
        cout << "2. Modifica cliente\n";
        cout << "3. Rimuovi cliente\n";
        cout << "4. Visualizza clienti\n";
        cout << "5. Gestisci interazioni cliente\n";
        cout << "6. Salva dati\n";
        cout << "7. Carica dati\n";
        cout << "0. Esci\n";
        cout << "\n";
        cout << "Scegli un'opzione: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                /* 
                 * Aggiungi un nuovo cliente.
                 * Richiede i dettagli del cliente e lo aggiunge al sistema.
                 */
                string idStr, firstName, lastName, phone, email;
                cout << "Inserisci ID cliente: ";
                cin >> idStr;
                if (!Client::isValidId(idStr)) {
                    cout << "Errore: ID non valido. Deve essere un numero.\n";
                    break;
                }
                int id = stoi(idStr);

                cout << "Inserisci Nome cliente: ";
                cin >> firstName;
                if (!Client::isValidName(firstName)) {
                    cout << "Errore: Nome non valido. Deve contenere solo lettere.\n";
                    break;
                }

                cout << "Inserisci Cognome cliente: ";
                cin >> lastName;
                if (!Client::isValidName(lastName)) {
                    cout << "Errore: Cognome non valido. Deve contenere solo lettere.\n";
                    break;
                }

                cout << "Inserisci Numero di telefono: ";
                cin >> phone;
                if (!Client::isValidPhone(phone)) {
                    cout << "Errore: Numero di telefono non valido.\n";
                    break;
                }

                cout << "Inserisci Email: ";
                cin >> email;
                if (!Client::isValidEmail(email)) {
                    cout << "Errore: Email non valida.\n";
                    break;
                }

                crm.addClient(Client(id, firstName, lastName, phone, email));
                cout << "Cliente aggiunto con successo.\n";
                break;
            }
            case 2: {
                /* 
                 * Modifica un cliente esistente.
                 * Permette di cercare il cliente e aggiornare i suoi dettagli.
                 */
                crm.editClient();
                break;
            }
            case 3: {
                /* 
                 * Rimuovi un cliente dal sistema.
                 * Permette di cercare il cliente e rimuoverlo dalla lista.
                 */
                crm.removeClient();
                break;
            }
            case 4: {
                /* 
                 * Visualizza tutti i clienti nel sistema.
                 * Stampa i dettagli di ogni cliente.
                 */
                crm.viewClients();
                break;
            }
            case 5: {
                /* 
                 * Gestisci le interazioni di un cliente.
                 * Permette di aggiungere, visualizzare, modificare o rimuovere interazioni.
                 */
                crm.manageClientInteractions();
                break;
            }
            case 6: {
                /* 
                 * Salva i dati del sistema CRM in un file.
                 * Utilizza il nome del file specificato per salvare i dati.
                 */
                if (FileManager::save(crm, filename)) {
                    cout << "Dati salvati con successo nel file data.txt.\n";
                }
                break;
            }
            case 7: {
                /* 
                 * Carica i dati del sistema CRM da un file.
                 * Utilizza il nome del file specificato per caricare i dati.
                 */
                if (FileManager::load(crm, filename)) {
                    cout << "Dati caricati con successo dal file data.txt.\n";
                }
                break;
            }
            case 0: {
                /* 
                 * Esci dal programma.
                 * Termina l'esecuzione del programma.
                 */
                cout << "Uscita dal programma.\n";
                cout << "--------------------------------\n";
                break;
            }
            default: {
                /* 
                 * Gestione di opzione non valida.
                 * Mostra un messaggio di errore.
                 */
                cout << "Opzione non valida. Riprova.\n";
                break;
            }
        }
    } while (choice != 0);

    return 0;
}