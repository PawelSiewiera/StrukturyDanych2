#include "Heap.h"
#include <stdexcept>

Heap::Heap() : size(0), capacity(10) {
    heapArray = new Node[capacity];
}

Heap::~Heap() {
    delete[] heapArray;
}

void Heap::resize_up() {
    capacity *= 2;
    Node* newArray = new Node[capacity];
    for (std::size_t i = 0; i < size; ++i)
        newArray[i] = heapArray[i];
    delete[] heapArray;
    heapArray = newArray;
}

void Heap::resize_down() {
    if (capacity > 10 && size <= capacity / 3) {
        capacity /= 2;
        Node* newArray = new Node[capacity];
        for (std::size_t i = 0; i < size; ++i)
            newArray[i] = heapArray[i];
        delete[] heapArray;
        heapArray = newArray;
    }
}

void Heap::swap_nodes(std::size_t i, std::size_t j) {
    Node temp = heapArray[i];
    heapArray[i] = heapArray[j];
    heapArray[j] = temp;
}

void Heap::sift_up(std::size_t index) {
    while (index > 0 && heapArray[index].priority > heapArray[parent(index)].priority) {
        swap_nodes(index, parent(index));
        index = parent(index);
    }
}

void Heap::sift_down(std::size_t index) {
    while (true) {
        std::size_t l = left(index);
        std::size_t r = right(index);
        std::size_t largest = index;

        if (l < size && heapArray[l].priority > heapArray[largest].priority) {
            largest = l;
        }
        if (r < size && heapArray[r].priority > heapArray[largest].priority) {
            largest = r;
        }
        if (largest != index) {
            swap_nodes(index, largest);
            index = largest;
        } else break;
    }
}

void Heap::insert(int value, int priority) {
    // Check uniqueness
    for (std::size_t i = 0; i < size; ++i) {
        if (heapArray[i].value == value) return;
    }

    if (size == capacity) resize_up();
    heapArray[size++] = {value, priority};
    sift_up(size - 1);
}

int Heap::peek() const {
    if (size == 0) throw std::out_of_range("Heap is empty");
    return heapArray[0].value;
}

int Heap::extract_max() {
    if (size == 0) throw std::out_of_range("Heap is empty");

    int maxValue = heapArray[0].value;
    heapArray[0] = heapArray[size - 1];
    --size;
    resize_down();
    if (size > 0) sift_down(0);
    return maxValue;
}

void Heap::change_priority(int value, int new_priority) {
    for (std::size_t i = 0; i < size; ++i) {
        if (heapArray[i].value == value) {
            int old_priority = heapArray[i].priority;
            heapArray[i].priority = new_priority;
            if (new_priority > old_priority)
                sift_up(i);
            else
                sift_down(i);
            return;
        }
    }
    throw std::invalid_argument("Value not found");
}

std::size_t Heap::get_size() const {
    return size;
}
