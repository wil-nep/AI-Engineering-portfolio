#ifndef INTERACTION_H
#define INTERACTION_H

#include <string>

/* 
 * Classe Interaction.
 * Rappresenta un'interazione associata a un cliente.
 * Può essere un contratto o un appuntamento.
 */
class Interaction {
private:
    std::string type;   
    std::string date;   
    std::string time;    
    std::string details; 

public:
    /* 
     * Costruttore per interazioni di tipo contratto.
     */
    Interaction(const std::string& type, const std::string& date, const std::string& details);

    /* 
     * Costruttore per interazioni di tipo appuntamento.
     */
    Interaction(const std::string& type, const std::string& date, const std::string& details, const std::string& time);

    /* 
     * Getter per ottenere il tipo di interazione.
     */
    const std::string& getType() const;

    /* 
     * Getter per ottenere la data dell'interazione.
     */
    const std::string& getDate() const;

    /* 
     * Getter per ottenere l'ora dell'interazione.
     */
    const std::string& getTime() const;

    /* 
     * Getter per ottenere i dettagli dell'interazione.
     */
    const std::string& getDetails() const;

    /* 
     * Setter per aggiornare i dettagli dell'interazione.
     */
    void setDetails(const std::string& newDetails);

    /* 
     * Stampa i dettagli dell'interazione.
     */
    void print() const;
};

#endif