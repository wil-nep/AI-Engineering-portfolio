"""
importo le librerie necessarie
"""

import json
import re

"""
Definisco la Classe Contatto che rappresenta un contatto nella rubrica
"""

class Contact:

    """
    inizializzo gli attributi della classe incapsulandoli con i metodi getter e setter
    """

    def __init__(self, name, surname, phone, email, group="Generale"):
        self._name = name
        self._surname = surname
        self._phone = phone
        self._email = email
        self._group = group

    """
    metodi getter e setter per gli attributi della classe
    """

    @property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        if not value.strip():
            raise ValueError("Il nome non può essere vuoto.")
        self._name = value

    @property
    def surname(self):
        return self._surname

    @surname.setter
    def surname(self, value):
        if not value.strip():
            raise ValueError("Il cognome non può essere vuoto.")
        self._surname = value

    @property
    def phone(self):
        return self._phone

    @phone.setter
    def phone(self, value):
        if not value.strip():
            raise ValueError("Il numero non può essere vuoto.")
        self._phone = value
 
    @property
    def email(self):
        return self._email

    @email.setter
    def email(self, value):
        if not value.strip():
            raise ValueError("L'email non può essere vuota.")
        self._email = value

    @property
    def group(self):
        return self._group
    
    @group.setter
    def group(self, value):
        if not value.strip():
            raise ValueError("L'email non può essere vuota.")
        self._group = value

    """
    metodo per convertire il contatto in un dizionario
    """

    def to_dict(self):
      return {
        "name": self.name,
        "surname": self.surname,
        "phone": self.phone,
        "email": self.email,
        "group": self.group
      }

    """
    metodo per convertire il contatto in una stringa
    """

    def __str__(self):
        return (f"{self.name}\t{self.surname}\t{self.phone}\t{self.email}\t{self.group}")
    def __repr__(self):
        return self.__str__()
    
    """
    ora inserisco i metodi statici di controllo per le informazioni come email e numero di telefono
    nel primo controllo che l'email abbia il formato nome@dominio.estensione con come  caratteri obbligatori @ e . e che l estensione si almeno di due lettere
    nel secondo controllo che il numero
    """

    @staticmethod
    def email_utils(email):
        pattern = r'^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$'
        return re.match(pattern, email) is not None
    @staticmethod
    def phone_utils(phone):
        pattern = r'^\+?[0-9]+$'
        return re.match(pattern, phone) is not None


""" 
Definisco la Classe AddressBook che rappresenta la rubrica dei contatti
"""

class AddressBook:

    """    
    inizializzo gli attributi della classe
    """

    def __init__(self):
        self._contacts = []
    
    """
    metodo getter e setter per i contatti
    """

    @property
    def contacts(self):
        return self._contacts

    @contacts.setter
    def contacts(self, value):
        if not isinstance(value, list):
            raise ValueError("L'attributo 'contacts' deve essere una lista.")
        self._contacts = value
    
    """
    metodo per visualizzare i contatti sia in ordine alfabetico che per gruppi
    se non ci sono contatti viene restituito un messaggio di errore
    """

    def view_contacts(self):
        print("Vuoi visualizzare:")
        print("1. Tutti i contatti")
        print("2. Contatti per gruppo")
        option = input("Inserisci 1 o 2: ")
        if option == '1':
            self.sort_by_name_and_surname()
            if not self.contacts:
                print("La rubrica è vuota.")
            else:
                print(f"\n{"Nome":<15}{"Cognome":<15}{"Numero":<15}{"Email":<25}{"Gruppo":<15}")
                print("-" * 90)
                for contact in self.contacts:
                    print(f"\n{contact.name:<15}{contact.surname:<15}{contact.phone:<15}{contact.email:<25}{contact.group:<15}")
        elif option == '2':
            group = input("Inserisci il nome del gruppo da visualizzare: ").strip()
            results = [contact for contact in self.contacts if contact.group.lower() == group.lower()]
            if not results:
                print(f"Nessun contatto trovato nel gruppo '{group}'.")
            else:
                print(f"Contatti nel gruppo '{group}':")
                print(f"\n{"Nome":<15}{"Cognome":<15}{"Numero":<15}{"Email":<25}{"Gruppo":<15}")
                self.sort_by_name_and_surname()
                print("-" * 90)
                for contact in results:
                    print(f"\n{contact.name:<15}{contact.surname:<15}{contact.phone:<15}{contact.email:<25}{contact.group:<15}")
        else:
            print("Scelta non valida. Riprova.")

    """
    metodo per ordinare i contatti per nome e cognome
    """

    def sort_by_name_and_surname(self):
        self.contacts.sort(key=lambda contact: (contact.name.lower(), contact.surname.lower()))

    """
    metodo per aggiungere un contatto con relativi controlli su numero e email
    """

    def add_contact(self):
        print("Aggiungi un nuovo contatto:")
        name = input("Nome: ").strip()
        surname = input("Cognome: ").strip()
        while True:
            phone = input("Numero: ").strip()
            if Contact.phone_utils(phone):
                break
            print("Numero non valido. Inserisci un numero valido (solo cifre e opzionalmente un '+' all'inizio).")
        while True:
            email = input("Email: ").strip()
            if Contact.email_utils(email):
                break
            print("Email non valida. Inserisci un'email valida (es. nome@dominio.estensione).")
        group = input("Inserisci il gruppo del contatto (es. Famiglia, Amici, Lavoro): ").strip() or "Generale"
        new_contact = Contact(name, surname, phone, email, group)
        self._contacts.append(new_contact)
        print("Contatto aggiunto con successo!")

    
    """
    metodo per salvare un nuovo contatto
    """

    def save_contacts(self, file_path):
      with open(file_path, 'w') as file:
            json.dump([contact.to_dict() for contact in self.contacts], file)

    """
    metodo per caricare i contatti con relativi controlli
    se il file non esiste viene creato un file vuoto
    se il file è vuoto viene restituito un messaggio di errore
    se il file è danneggiato viene restituito un messaggio di errore
    """

    def load_contact(self, file_path):
        try:
            with open(file_path, 'r') as file:
                contacts_dict = json.load(file)
                self.contacts = [Contact(**contact) for contact in contacts_dict]
        except FileNotFoundError:
            self.contacts = []
        except json.JSONDecodeError:
            print("Errore nel caricamento dei contatti. Il file potrebbe essere vuoto o danneggiato.")
        
        
    """
    metodo per cercare un contatto per nome o per cognome e stampare i risultati
    valido ache per la ricerca di nomi o cognomi parziali
    se non viene trovato un contatto viene restituito un messaggio di errore
    """

    def search_contact(self):
        print("Vuoi cercare per:")
        print("1. Nome")
        print("2. Cognome")
        print("3. Gruppo")
        option = input("Inserisci 1,2 o 3: ")
        if option == '1':
            criteria = input("Inserisci il nome del contatto da cercare: ").strip().lower()
            results = [contact for contact in self.contacts if criteria in contact.name.lower()]
        elif option == '2':
            criteria = input("Inserisci il cognome del contatto da cercare: ").strip().lower()
            results = [contact for contact in self.contacts if criteria in contact.surname.lower()]
        elif option == '3':
            criteria = input("Inserisci il nome del gruppo da cercare: ").strip().lower()
            results = [contact for contact in self.contacts if criteria == contact.group.lower()]
        else:
            print("Scelta non valida. Riprova.")
            return []
        if not results:
            print("Nessun contatto trovato.")
        elif len(results) == 1:
            print(f"\nContatto trovato:")
            print(f"{'Nome':<15}{'Cognome':<15}{'Numero':<15}{'Email':<25}{'Gruppo':<15}")
            print("-" * 90)
            print(f"{results[0].name:<15}{results[0].surname:<15}{results[0].phone:<15}{results[0].email:<25}{results[0].group:<15}")
        else:
            print(f"\nTrovati {len(results)} contatti:")
            print(f"{'ID':<5}{'Nome':<15}{'Cognome':<15}{'Numero':<15}{'Email':<25}{'Gruppo':<15}")
            print("-" * 90)
            for i, contact in enumerate(results, start=1):
                print(f"{i:<5}{contact.name:<15}{contact.surname:<15}{contact.phone:<15}{contact.email:<25}{contact.group:<15}")
        return results

    """
    metodo per eliminare un contatto e stampare i risultati
    se non viene trovato un contatto viene restituito un messaggio di errore
    se viene trovato più di un contatto viene restituito una lista di contatti
    """

    def delete_contact(self, name):
        contact = next((c for c in self.contacts if c.name == name), None)
        if contact:
            confirm = input(f"Sei sicuro di voler eliminare il contatto '{contact.name} {contact.surname}'? (s/n): ").strip().lower()
            if confirm == 's':
                self._contacts.remove(contact)
                print("Eliminazione avvenuta con successo.")
            elif confirm == 'n':
                print("Eliminazione annullata.")
            
    """
    metodo per modificare un contatto, sia interamente che solamente una parte con relativi controlli a numero e email
    se non viene trovato un contatto viene restituito un messaggio di errore
    se viene trovato più di un contatto viene restituito una lista di contatti
    """

    def edit_contact(self, name):
        contact_found = next((c for c in self.contacts if c.name == name), None)
        if not contact_found:
            print(f"Nessun contatto trovato con il nome '{name}'.")
            return
        print("Vuoi modificare:")
        print("1. L'intero contatto")
        print("2. Solo una parte del contatto")
        option = input("Inserisci 1 o 2: ")
        if option == '1':
            contact_found.name = input(f"Nome ({contact_found.name}): ") or contact_found.name
            contact_found.surname = input(f"Cognome ({contact_found.surname}): ") or contact_found.surname
            while True:
                new_phone = input(f"Numero ({contact_found.phone}): ").strip()
                if Contact.phone_utils(new_phone):
                    contact_found.phone = new_phone
                    break
                print("Numero non valido. Inserisci un numero valido (solo cifre e opzionalmente un '+' all'inizio).")
            while True:
                new_email = input(f"E-mail ({contact_found.email}): ").strip()
                if Contact.email_utils(new_email):
                    contact_found.email = new_email
                    break
                print("Email non valida. Inserisci un'email valida (es. email@gmail.com).")
            contact_found.group = input(f"Gruppo ({contact_found.group}): ") or contact_found.group
            print("Contatto modificato con successo.")
        elif option == '2':
            print("Quale campo vuoi modificare?")
            print("1. Nome")
            print("2. Cognome")
            print("3. Numero")
            print("4. Email")
            print("5. Gruppo")
            field = input("Inserisci il numero corrispondente al campo da modificare: ")
            if field == '1':
                contact_found.name = input(f"Nuovo Nome ({contact_found.name}): ") or contact_found.name
            elif field == '2':
                contact_found.surname = input(f"Nuovo Cognome ({contact_found.surname}): ") or contact_found.surname
            elif field == '3':
                while True:
                    new_phone = input(f"Nuovo Numero ({contact_found.phone}): ").strip()
                    if Contact.phone_utils(new_phone):
                        contact_found.phone = new_phone
                        break
                    print("Numero non valido. Inserisci un numero valido (solo cifre e opzionalmente un '+' all'inizio).")
            elif field == '4':
                while True:
                    new_email = input(f"Nuova Email ({contact_found.email}): ").strip()
                    if Contact.email_utils(new_email):
                        contact_found.email = new_email
                        break
                    print("Email non valida. Inserisci un'email valida (es. email@gmail.com).")
            elif field == '5':
                new_group = input(f"Nuovo Gruppo ({contact_found.group}): ").strip() or contact_found.group
                contact_found.group = new_group
            else:
                print("Scelta non valida. Nessuna modifica effettuata.")
                return
            print("Campo modificato con successo.")
        else:
            print("Scelta non valida. Nessuna modifica effettuata.")



