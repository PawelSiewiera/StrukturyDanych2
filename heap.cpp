#include "heap.h"
#include <stdexcept>
#include <algorithm>

MaxHeap::MaxHeap() = default;

MaxHeap::~MaxHeap() = default;

std::size_t MaxHeap::parent(std::size_t i) { return (i - 1) / 2; }

std::size_t MaxHeap::left(std::size_t i) { return 2 * i + 1; }

std::size_t MaxHeap::right(std::size_t i) { return 2 * i + 2; }

void MaxHeap::swap_nodes(std::size_t i, std::size_t j) {
    std::swap(heap_[i], heap_[j]);
    index_map_[heap_[i].value] = i;
    index_map_[heap_[j].value] = j;
}

void MaxHeap::sift_up(std::size_t i) {
    while (i > 0) {
        std::size_t p = parent(i);
        if (heap_[i].priority > heap_[p].priority) {
            swap_nodes(i, p);
            i = p;
        } else {
            break;
        }
    }
}

void MaxHeap::sift_down(std::size_t i) {
    std::size_t n = heap_.size();
    while (true) {
        std::size_t l = left(i);
        std::size_t r = right(i);
        std::size_t largest = i;
        if (l < n && heap_[l].priority > heap_[largest].priority) largest = l;
        if (r < n && heap_[r].priority > heap_[largest].priority) largest = r;
        if (largest != i) {
            swap_nodes(i, largest);
            i = largest;
        } else {
            break;
        }
    }
}

void MaxHeap::insert(int value, int priority) {
    if (index_map_.count(value)) {
        throw std::invalid_argument("Value already in heap");
    }
    heap_.push_back({priority, value});
    std::size_t idx = heap_.size() - 1;
    index_map_[value] = idx;
    sift_up(idx);
}

int MaxHeap::peek() const {
    if (heap_.empty()) {
        throw std::out_of_range("Heap is empty");
    }
    return heap_[0].value;
}

int MaxHeap::extract_max() {
    if (heap_.empty()) {
        throw std::out_of_range("Heap is empty");
    }
    int maxVal = heap_[0].value;
    swap_nodes(0, heap_.size() - 1);
    index_map_.erase(heap_.back().value);
    heap_.pop_back();
    if (!heap_.empty()) sift_down(0);
    return maxVal;
}

void MaxHeap::change_priority(int value, int new_priority) {
    auto it = index_map_.find(value);
    if (it == index_map_.end()) {
        throw std::invalid_argument("Value not found");
    }
    std::size_t idx = it->second;
    int old_priority = heap_[idx].priority;
    heap_[idx].priority = new_priority;
    if (new_priority > old_priority) {
        sift_up(idx);
    } else if (new_priority < old_priority) {
        sift_down(idx);
    }
}

std::size_t MaxHeap::size() const noexcept {
    return heap_.size();
}
