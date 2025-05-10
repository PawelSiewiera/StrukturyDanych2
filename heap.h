#ifndef HEAP_HPP
#define HEAP_HPP

#include <cstddef>

class Heap {
private:
    struct Node {
        int value;
        int priority;
    };

    Node* heapArray;
    std::size_t size;
    std::size_t capacity;

    void sift_up(std::size_t index);
    void sift_down(std::size_t index);
    void swap_nodes(std::size_t i, std::size_t j);
    void resize_up();
    void resize_down();

    std::size_t parent(std::size_t i) const { return (i - 1) / 2; }
    std::size_t left(std::size_t i) const { return 2 * i + 1; }
    std::size_t right(std::size_t i) const { return 2 * i + 2; }

public:
    Heap();
    ~Heap();

    void insert(int value, int priority);
    int peek() const;
    int extract_max();
    int find_max() const;
    void change_priority(int value, int new_priority);
    std::size_t get_size() const;
};

#endif // HEAP_HPP
