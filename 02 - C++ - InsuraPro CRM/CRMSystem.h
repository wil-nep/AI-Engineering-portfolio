#ifndef CRMSYSTEM_H
#define CRMSYSTEM_H

#include <vector>
#include <string>
#include "Client.h"

/* 
 * Classe CRMSystem.
 * Gestisce i clienti e le loro interazioni in un sistema CRM.
 */
class CRMSystem {
private:
    std::vector<Client> clients;

public:
    /* 
     * Aggiunge un nuovo cliente al sistema.
     */
    void addClient(const Client& client);

    /* 
     * Modifica un cliente esistente.
     * Permette di cercare il cliente e aggiornare i suoi dettagli.
     */
    void editClient();

    /* 
     * Rimuove un cliente dal sistema.
     * Permette di cercare il cliente e rimuoverlo dalla lista.
     */
    void removeClient();

    /* 
     * Visualizza tutti i clienti nel sistema.
     * Stampa i dettagli di ogni cliente.
     */
    void viewClients() const;

    /* 
     * Trova un cliente per ID.
     */
    Client* findClientById(int id);

    /* 
     * Trova clienti per nome.
     */
    std::vector<Client*> findClientsByName(const std::string& firstName);

    /* 
     * Trova clienti per cognome.
     */
    std::vector<Client*> findClientsBySurname(const std::string& lastName);

    /* 
     * Gestisce le interazioni di un cliente.
     * Permette di aggiungere, visualizzare, modificare o rimuovere interazioni.
     */
    void manageClientInteractions();

    /* 
     * Ottiene la lista dei clienti.
     */
    const std::vector<Client>& getClients() const;

    /* 
     * Stampa una lista di clienti.
     */
    void printClientList(const std::vector<Client*>& matches) const;

    /* 
     * Pulisce la lista dei clienti.
     * Rimuove tutti i clienti dal sistema.
     */
    void clearClients();
};

#endif