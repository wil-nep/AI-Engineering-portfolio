#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "CRMSystem.h"
#include <string>

/* 
 * Classe FileManager.
 * Gestisce il salvataggio e il caricamento dei dati del sistema CRM.
 */
class FileManager {
public:
    /* 
     * Salva i dati del sistema CRM in un file.
     */
    static bool save(const CRMSystem& crm, const std::string& filename);

    /* 
     * Carica i dati del sistema CRM da un file.
     */
    static bool load(CRMSystem& crm, const std::string& filename);
};

#endif