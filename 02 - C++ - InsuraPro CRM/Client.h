#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <vector>
#include "Interaction.h"

/* 
 * Classe Client.
 * Rappresenta un cliente con ID, nome, cognome, numero di telefono, email e interazioni.
 */
class Client {
private:
    int id;                     
    std::string firstName;     
    std::string lastName;       
    std::string phone;          
    std::string email;          
    std::vector<Interaction> interactions;

public:
    /* 
     * Costruttore della classe Client.
     * Inizializza un cliente con ID, nome, cognome, numero di telefono e email.
     */
    Client(int id, const std::string& firstName, const std::string& lastName, const std::string& phone, const std::string& email);

    /* 
     * Getter per ottenere i dettagli del cliente.
     * Include ID, nome, cognome, numero di telefono, email e interazioni.
     */
    int getId() const;
    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getPhone() const;
    const std::string& getEmail() const;
    const std::vector<Interaction>& getInteractions() const;

    /* 
     * Setter per aggiornare i dettagli del cliente.
     * Permette di modificare ID, nome, cognome, numero di telefono e email.
     */
    void setId(int newId);
    void setFirstName(const std::string& newFirstName);
    void setLastName(const std::string& newLastName);
    void setPhone(const std::string& newPhone);
    void setEmail(const std::string& newEmail);

    /* 
     * Funzioni di validazione per verificare la correttezza dei campi.
     * Controlla ID, nome, numero di telefono e email.
     */
    static bool isValidId(const std::string& id);
    static bool isValidName(const std::string& name);
    static bool isValidPhone(const std::string& phone);
    static bool isValidEmail(const std::string& email);

    /* 
     * Gestione delle interazioni del cliente.
     * Permette di aggiungere interazioni e ordinarle per data.
     */
    void addInteraction(const Interaction& interaction);
    void sortInteractionsByDate();

    /* 
     * Stampa i dettagli del cliente.
     * Include ID, nome, cognome, numero di telefono, email e tutte le interazioni.
     */
    void printDetails() const;
};

#endif