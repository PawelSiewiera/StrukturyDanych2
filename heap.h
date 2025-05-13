#ifndef HEAP_H
#define HEAP_H

#include <cstddef>

/**
 * @brief Klasa reprezentująca kopiec maksymalny
 */
class Heap {
private:
    struct Node {
        int value;     // wartość elementu
        int priority;  //priorytet elementu
    };

    Node* heapArray;      // dynamiczna tablica kopca
    std::size_t size;     // aktualny rozmiar
    std::size_t capacity; // pojemność kopca

    // Pomocnicze metody prywatne
    void sift_up(std::size_t index);     // przywraca porządek kopca w górę
    void sift_down(std::size_t index);   // przywraca porządek kopca w dół
    void swap_nodes(std::size_t i, std::size_t j); //zamienia dwa węzły
    void resize_up();
    void resize_down();

    std::size_t parent(std::size_t i) const { return (i - 1) / 2; }
    std::size_t left(std::size_t i) const { return 2 * i + 1; }
    std::size_t right(std::size_t i) const { return 2 * i + 2; }

public:
    Heap();                //konstruktor
    ~Heap();               // destruktor

    /// @brief Wstawia element do kopca
    void insert(int value, int priority);

    /// @brief Zwraca element o najwyższym priorytecie (bez usuwania)
    int peek() const;

    /// @brief Zwraca i usuwa element o najwyższym priorytecie
    int extract_max();

    /// @brief Zmienia priorytet danego elementu
    void change_priority(int value, int new_priority);

    /// @brief Zwraca rozmiar kopca
    std::size_t get_size() const;
};

#endif // HEAP_H
