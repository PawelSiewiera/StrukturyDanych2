
#ifndef HEAP_H
#define HEAP_H

#include <cstddef>
#include <vector>
#include <unordered_map>
#include <stdexcept>


class MaxHeap {
public:
    MaxHeap();
    ~MaxHeap();


    void insert(int value, int priority);

    int peek() const;

    int extract_max();


    void change_priority(int value, int new_priority);


    std::size_t size() const noexcept;

private:
    struct Node {
        int priority;
        int value;
    };

    std::vector<Node> heap_;
    std::unordered_map<int, std::size_t> index_map_;

    static std::size_t parent(std::size_t i);
    static std::size_t left(std::size_t i);
    static std::size_t right(std::size_t i);

    void swap_nodes(std::size_t i, std::size_t j);
    void sift_up(std::size_t i);
    void sift_down(std::size_t i);
};

#endif // HEAP_H