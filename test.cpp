#include "test.h"
#include "heap.h"
#include "TablicaPriorytetowa.hpp"
#include <vector>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

static int randomValue() {
    return rand();
}

static int randomPriority(int size) {
    return rand() % (size * 10);
}

void test::test_Insert(int size, int samples, int operations) {
    long long heap_sum = 0, array_sum = 0;
    for (int e = 0; e < samples; ++e) {
        MaxHeap heap;
        TablicaPriorytetowa arr;

        for (int i = 0; i < size; ++i) {
            int v = randomValue(), p = randomPriority(size);
            heap.insert(v, p);
            arr.insert(v, p);
        }

        for (int i = 0; i < operations; ++i) {
            int v = randomValue(), p = randomPriority(size);

            auto t0 = high_resolution_clock::now();
            heap.insert(v, p);
            auto t1 = high_resolution_clock::now();
            heap_sum += duration_cast<nanoseconds>(t1 - t0).count();

            auto t2 = high_resolution_clock::now();
            arr.insert(v, p);
            auto t3 = high_resolution_clock::now();
            array_sum += duration_cast<nanoseconds>(t3 - t2).count();
        }
    }
    double avg_heap = double(heap_sum) / (samples * operations);
    double avg_array = double(array_sum) / (samples * operations);

    cout << "Sredni czas insert (MaxHeap): " << avg_heap << " ns\n";
    cout << "Sredni czas insert (TablicaPriorytetowa): " << avg_array << " ns\n";
}

void test::test_ExtractMax(int size, int samples, int operations) {
    long long heap_sum = 0, array_sum = 0;
    for (int e = 0; e < samples; ++e) {
        MaxHeap heap;
        TablicaPriorytetowa arr;

        for (int i = 0; i < size + operations; ++i) {
            int v = randomValue(), p = randomPriority(size);
            heap.insert(v, p);
            arr.insert(v, p);
        }

        for (int i = 0; i < operations; ++i) {
            auto t0 = high_resolution_clock::now();
            heap.extract_max();
            auto t1 = high_resolution_clock::now();
            heap_sum += duration_cast<nanoseconds>(t1 - t0).count();

            auto t2 = high_resolution_clock::now();
            arr.extract_max();
            auto t3 = high_resolution_clock::now();
            array_sum += duration_cast<nanoseconds>(t3 - t2).count();
        }
    }
    double avg_heap = double(heap_sum) / (samples * operations);
    double avg_array = double(array_sum) / (samples * operations);

    cout << "Sredni czas extract_max (MaxHeap): " << avg_heap << " ns\n";
    cout << "Sredni czas extract_max (TablicaPriorytetowa): " << avg_array << " ns\n";
}

void test::test_FindMax(int size, int samples, int operations) {
    long long heap_sum = 0, array_sum = 0;
    for (int e = 0; e < samples; ++e) {
        MaxHeap heap;
        TablicaPriorytetowa arr;

        for (int i = 0; i < size; ++i) {
            int v = randomValue(), p = randomPriority(size);
            heap.insert(v, p);
            arr.insert(v, p);
        }

        for (int i = 0; i < operations; ++i) {
            auto t0 = high_resolution_clock::now();
            heap.peek();
            auto t1 = high_resolution_clock::now();
            heap_sum += duration_cast<nanoseconds>(t1 - t0).count();

            auto t2 = high_resolution_clock::now();
            arr.find_max();
            auto t3 = high_resolution_clock::now();
            array_sum += duration_cast<nanoseconds>(t3 - t2).count();
        }
    }
    double avg_heap = double(heap_sum) / (samples * operations);
    double avg_array = double(array_sum) / (samples * operations);

    cout << "Sredni czas find_max (MaxHeap): " << avg_heap << " ns\n";
    cout << "Sredni czas find_max (TablicaPriorytetowa): " << avg_array << " ns\n";
}

void test::test_ModifyKey(int size, int samples, int operations) {
    long long heap_sum = 0, array_sum = 0;
    for (int e = 0; e < samples; ++e) {
        MaxHeap heap;
        TablicaPriorytetowa arr;
        vector<int> keys;

        for (int i = 0; i < size; ++i) {
            int v = randomValue(), p = randomPriority(size);
            heap.insert(v, p);
            arr.insert(v, p);
            keys.push_back(v);
        }

        for (int i = 0; i < operations; ++i) {
            int idx = rand() % keys.size();
            int v = keys[idx];
            int p = randomPriority(size);

            auto t0 = high_resolution_clock::now();
            heap.change_priority(v, p);
            auto t1 = high_resolution_clock::now();
            heap_sum += duration_cast<nanoseconds>(t1 - t0).count();

            auto t2 = high_resolution_clock::now();
            arr.modify_key(v, p);
            auto t3 = high_resolution_clock::now();
            array_sum += duration_cast<nanoseconds>(t3 - t2).count();
        }
    }
    double avg_heap = double(heap_sum) / (samples * operations);
    double avg_array = double(array_sum) / (samples * operations);

    cout << "Sredni czas modify_key (MaxHeap): " << avg_heap << " ns\n";
    cout << "Sredni czas modify_key (TablicaPriorytetowa): " << avg_array << " ns\n";
}

void test::test_Size(int size, int samples, int operations) {
    long long heap_sum = 0, array_sum = 0;
    for (int e = 0; e < samples; ++e) {
        MaxHeap heap;
        TablicaPriorytetowa arr;

        for (int i = 0; i < size; ++i) {
            int v = randomValue(), p = randomPriority(size);
            heap.insert(v, p);
            arr.insert(v, p);
        }

        for (int i = 0; i < operations; ++i) {
            auto t0 = high_resolution_clock::now();
            heap.size();
            auto t1 = high_resolution_clock::now();
            heap_sum += duration_cast<nanoseconds>(t1 - t0).count();

            auto t2 = high_resolution_clock::now();
            arr.return_size();
            auto t3 = high_resolution_clock::now();
            array_sum += duration_cast<nanoseconds>(t3 - t2).count();
        }
    }
    double avg_heap = double(heap_sum) / (samples * operations);
    double avg_array = double(array_sum) / (samples * operations);

    cout << "Sredni czas return_size (MaxHeap): " << avg_heap << " ns\n";
    cout << "Sredni czas return_size (TablicaPriorytetowa): " << avg_array << " ns\n";
}
