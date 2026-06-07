#include "Interaction.h"
#include <iostream>

using namespace std;

/* 
 * Costruttore per interazioni di tipo contratto.
 * Inizializza un'interazione con tipo, data e dettagli.
 */
Interaction::Interaction(const std::string& type, const std::string& date, const std::string& details)
    : type(type), date(date), details(details), time("") {}

/* 
 * Costruttore per interazioni di tipo appuntamento.
 * Inizializza un'interazione con tipo, data, dettagli e ora.
 */
Interaction::Interaction(const std::string& type, const std::string& date, const std::string& details, const std::string& time)
    : type(type), date(date), details(details), time(time) {}

/* 
 * Getter per ottenere il tipo di interazione.
 */
const std::string& Interaction::getType() const {
    return type;
}

/* 
 * Getter per ottenere la data dell'interazione.
 */
const std::string& Interaction::getDate() const {
    return date;
}

/* 
 * Getter per ottenere l'ora dell'interazione.
 */
const std::string& Interaction::getTime() const {
    return time;
}

/* 
 * Getter per ottenere i dettagli dell'interazione.
 */
const std::string& Interaction::getDetails() const {
    return details;
}

/* 
 * Setter per aggiornare i dettagli dell'interazione.
 */
void Interaction::setDetails(const std::string& newDetails) {
    details = newDetails;
}

/* 
 * Stampa i dettagli dell'interazione.
 */
void Interaction::print() const {
    cout << "Tipo: " << type << ", Data: " << date;
    if (!time.empty()) {
        cout << ", Ora: " << time;
    }
    cout << ", Dettagli: " << details << "\n";
}