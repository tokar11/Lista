#include <iostream>

/**
 * @class DoublyLinkedList
 * @brief Implementacja podwójnie powiązanego listy.
 *
 * Ta klasa implementuje listę podwójnie powiązaną z operacjami dodawania,
 * usuwania oraz wyświetlania elementów w różnych porządkach.
 */
class DoublyLinkedList {
private:
    /**
     * @struct Node
     * @brief Struktura reprezentująca pojedynczy węzeł w liście.
     *
     * Przechowuje dane oraz wskaźniki na poprzedni i następny węzeł.
     */
    struct Node {
        int data; ///< Dane przechowywane w węźle.
        Node* prev; ///< Wskaźnik na poprzedni węzeł.
        Node* next; ///< Wskaźnik na następny węzeł.

        /**
         * @brief Konstruktor węzła.
         *
         * Inicjalizuje węzeł z określoną wartością i wskaźnikami na nullptr.
         * @param val Wartość, którą przechowuje węzeł.
         */
        Node(int val) : data(val), prev(nullptr), next(nullptr) {}
    };

    Node* head; ///< Wskaźnik na pierwszy węzeł listy.
    Node* tail; ///< Wskaźnik na ostatni węzeł listy.

public:
    /**
     * @brief Konstruktor klasy DoublyLinkedList.
     *
     * Inicjalizuje pustą listę.
     */
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    /**
     * @brief Destruktor klasy DoublyLinkedList.
     *
     * Zwalnia pamięć zajmowaną przez listę.
     */
    ~DoublyLinkedList() {
        Clear();
    }

    /**
     * @brief Dodaje element na początek listy.
     *
     * Tworzy nowy węzeł i dodaje go na początek listy.
     * @param value Wartość, którą przechowa nowy węzeł.
     */
    void AddAtBeg(int value);

    /**
     * @brief Dodaje element na koniec listy.
     *
     * Tworzy nowy węzeł i dodaje go na koniec listy.
     * @param value Wartość, którą przechowa nowy węzeł.
     */
    void AddAtEnd(int value);

    /**
     * @brief Dodaje element na określony indeks listy.
     *
     * Tworzy nowy węzeł i wstawia go w odpowiednie miejsce w liście.
     * @param index Indeks, na którym ma zostać dodany element.
     * @param value Wartość, którą przechowa nowy węzeł.
     */
    void AddAtIndex(int index, int value);

    /**
     * @brief Usuwa element z początku listy.
     *
     * Usuwa pierwszy element z listy.
     */
    void RemoveFromBeg();

    /**
     * @brief Usuwa element z końca listy.
     *
     * Usuwa ostatni element z listy.
     */
    void RemoveFromEnd();

    /**
     * @brief Usuwa element z określonego indeksu listy.
     *
     * Usuwa element znajdujący się na wskazanym indeksie.
     * @param index Indeks elementu, który ma zostać usunięty.
     */
    void RemoveAtIndex(int index);

    /**
     * @brief Wyświetla wszystkie elementy listy od początku do końca.
     *
     * Funkcja wypisuje dane każdego węzła w liście, zaczynając od pierwszego węzła.
     */
    void display() const;

    /**
     * @brief Wyświetla wszystkie elementy listy w odwrotnej kolejności.
     *
     * Funkcja wypisuje dane każdego węzła w liście, zaczynając od ostatniego węzła.
     */
    void DisplayReverse() const;

    /**
     * @brief Czyści całą listę.
     *
     * Funkcja usuwa wszystkie węzły z listy.
     */
    void Clear();
};

/**
 * @brief Wyświetla menu opcji dostępnych w programie.
 *
 * Menu zawiera różne operacje, które użytkownik może wybrać do manipulowania listą.
 */
void menu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add item at the beginning of the list.\n";
    std::cout << "2. Add item at the end of the list.\n";
    std::cout << "3. Add item at a specified index.\n";
    std::cout << "4. Delete item from the beginning of the list.\n";
    std::cout << "5. Delete item from the end of the list.\n";
    std::cout << "6. Delete item from a specified index.\n";
    std::cout << "7. Display list\n";
    std::cout << "8. Display reversed list.\n";
    std::cout << "9. Clear list.\n";
    std::cout << "0. Exit.\n";
    std::cout << "Your choice: ";
}

/**
 * @brief Funkcja główna programu.
 *
 * Obsługuje interakcję z użytkownikiem, umożliwiając wybór różnych operacji na liście.
 * Użytkownik może wybierać operacje takie jak dodawanie, usuwanie elementów,
 * wyświetlanie listy oraz czyszczenie listy.
 *
 * @return Zwraca 0, gdy program kończy działanie.
 */
int main() {
    DoublyLinkedList list;
    int choice, value, index;

    do {
        menu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Enter value: ";
            std::cin >> value;
            list.AddAtBeg(value);
            break;
        case 2:
            std::cout << "Enter value: ";
            std::cin >> value;
            list.AddAtEnd(value);
            break;
        case 3:
            std::cout << "Enter index: ";
            std::cin >> index;
            std::cout << "Enter value: ";
            std::cin >> value;
            list.AddAtIndex(index, value);
            break;
        case 4:
            list.RemoveFromBeg();
            break;
        case 5:
            list.RemoveFromEnd();
            break;
        case 6:
            std::cout << "Enter index: ";
            std::cin >> index;
            list.RemoveAtIndex(index);
            break;
        case 7:
            std::cout << "List status: ";
            list.display();
            break;
        case 8:
            std::cout << "The list is in reverse order: ";
            list.DisplayReverse();
            break;
        case 9:
            list.Clear();
            std::cout << "List has been cleared\n";
            break;
        case 0:
            std::cout << "You left the program!\n";
            break;
        default:
            std::cout << "Incorrect case selection!\n";
        }
    } while (choice != 0);
    return 0;
}
