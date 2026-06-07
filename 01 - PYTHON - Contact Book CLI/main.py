"""
importo la classe AddressBook
"""

from models import AddressBook

"""
definizione della funzione principale
"""

def main():
    address_book = AddressBook()
    file_address_book = "rubrica.json"
    address_book.load_contact(file_address_book)

    """
    ciclo infinito per il menu principale
    """

    while True:
        print("\n--- Menu Rubrica ---")
        print("1. Aggiungi un contatto")
        print("2. Visualizza i contatti")
        print("3. Modifica un contatto")
        print("4. Cerca un contatto")
        print("5. Elimina un contatto")
        print("6. Salva ed Esci")

        option = input("\nScegli un'opzione (1-6): ")
        while option not in ['1', '2', '3', '4', '5', '6']:
            print("\nOpzione non valida. Inserisci un numero tra 1 e 6.")
            option = input("Scegli un'opzione (1-6): ")

        if option == '1':
            address_book.add_contact()
        elif option == '2':
            if not address_book.contacts:
                print("\nLa rubrica è vuota.")
            else:
                print("\nContatti della rubrica: ")
                print("-" * 90)
                address_book.view_contacts()
                print("-" * 90)
        elif option == '3':
            if not address_book.contacts:
                print("\nLa rubrica è vuota. Non puoi modificare contatti.")
            else:
                print("\nCerca il contatto da modificare:")
                print("-" * 90)
                results = address_book.search_contact()  
                if results:  
                    print("-" * 90)
                    if not results:
                        print("\nNessun contatto trovato.")
                    if len(results) == 1:  
                        address_book.edit_contact(results[0].name)
                    else:  
                        print("\nTrovati più contatti. Scegli quale modificare:")
                        while True:
                            try:
                                option = int(input("Inserisci il numero del contatto da modificare: ")) - 1
                                if 0 <= option < len(results):
                                    address_book.edit_contact(results[option].name)
                                    break
                                else:
                                    print("Scelta non valida. Riprova.")
                            except ValueError:
                                print("Input non valido. Inserisci un numero.")
        elif option == '4':
            if not address_book.contacts:
                print("\nLa rubrica è vuota. Non puoi cercare contatti.")
            else:
                results = address_book.search_contact()
                if not results:
                    print("\nNessun contatto trovato.")
        elif option == '5':
            if not address_book.contacts:
                print("\nLa rubrica è vuota. Non puoi eliminare contatti.")
            else:
                print("\nCerca il contatto da eliminare:")
                print("-" * 90)
                results = address_book.search_contact()  
                if results:
                    print("-" * 90) 
                    if len(results) == 1:  
                        address_book.delete_contact(results[0].name)
                    else:  
                        print("\nTrovati più contatti. Scegli quale eliminare:")
                        for i, contact in enumerate(results, start=1):
                            print(f"{i}. {contact.name} - {contact.phone} - {contact.email}")
                        while True:
                            try:
                                option = int(input("Inserisci il numero del contatto da eliminare: ")) - 1
                                if 0 <= option < len(results):
                                    address_book.delete_contact(results[option].name)
                                    break
                                else:
                                    print("Scelta non valida. Riprova.")
                            except ValueError:
                                print("Input non valido. Inserisci un numero.")
        elif option == '6':
            address_book.save_contacts(file_address_book)
            print("\nContatti salvati. Uscita dal programma.")
            break
if __name__ == "__main__":
    main()
