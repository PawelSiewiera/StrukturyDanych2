
#include "test.h"
#include "heap.h"
#include "generate_data.h" // generator losowych wartości
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
    long long sum = 0;
    for (int e = 0; e < samples; ++e) {
        MaxHeap<int,int> heap;
        // wstepne wypelnienie
        for (int i = 0; i < size; ++i)
            heap.insert(randomValue(), randomPriority(size));
        // pomiar insert
        for (int i = 0; i < operations; ++i) {
            int v = randomValue(), p = randomPriority(size);
            auto t0 = high_resolution_clock::now();
            heap.insert(v, p);
            auto t1 = high_resolution_clock::now();
            sum += duration_cast<nanoseconds>(t1 - t0).count();
        }
    }
    double avg = double(sum) / (samples * operations);
    cout << "Sredni czas insert: " << avg << " ns\n";
}

void test::test_ExtractMax(int size, int samples, int operations) {
    long long sum = 0;
    for (int e = 0; e < samples; ++e) {
        MaxHeap<int,int> heap;
        for (int i = 0; i < size + operations; ++i)
            heap.insert(randomValue(), randomPriority(size));
        // pomiar extract_max
        for (int i = 0; i < operations; ++i) {
            auto t0 = high_resolution_clock::now();
            heap.extract_max();
            auto t1 = high_resolution_clock::now();
            sum += duration_cast<nanoseconds>(t1 - t0).count();
        }
    }
    double avg = double(sum) / (samples * operations);
    cout << "Sredni czas extract_max: " << avg << " ns\n";
}

void test::test_FindMax(int size, int samples, int operations) {
    long long sum = 0;
    for (int e = 0; e < samples; ++e) {
        MaxHeap<int,int> heap;
        for (int i = 0; i < size; ++i)
            heap.insert(randomValue(), randomPriority(size));
        // pomiar find_max
        for (int i = 0; i < operations; ++i) {
            auto t0 = high_resolution_clock::now();
            heap.find_max();
            auto t1 = high_resolution_clock::now();
            sum += duration_cast<nanoseconds>(t1 - t0).count();
        }
    }
    double avg = double(sum) / (samples * operations);
    cout << "Sredni czas find_max: " << avg << " ns\n";
}

void test::test_ModifyKey(int size, int samples, int operations) {
    long long sum = 0;
    for (int e = 0; e < samples; ++e) {
        MaxHeap<int,int> heap;
        vector<int> keys;
        // wstepne wypelnienie i zapamietanie wartosci
        for (int i = 0; i < size; ++i) {
            int v = randomValue();
            heap.insert(v, randomPriority(size));
            keys.push_back(v);
        }
        // pomiar modify_key (losujemy istniejący element)
        for (int i = 0; i < operations; ++i) {
            int idx = rand() % keys.size();
            int v   = keys[idx];
            int p   = randomPriority(size);
            auto t0 = high_resolution_clock::now();
            heap.modify_key(v, p);
            auto t1 = high_resolution_clock::now();
            sum += duration_cast<nanoseconds>(t1 - t0).count();
        }
    }
    double avg = double(sum) / (samples * operations);
    cout << "Sredni czas modify_key: " << avg << " ns\n";
}

void test::test_Size(int size, int samples, int operations) {
    long long sum = 0;
    for (int e = 0; e < samples; ++e) {
        MaxHeap<int,int> heap;
        for (int i = 0; i < size; ++i)
            heap.insert(randomValue(), randomPriority(size));
        // pomiar return_size
        for (int i = 0; i < operations; ++i) {
            auto t0 = high_resolution_clock::now();
            heap.return_size();
            auto t1 = high_resolution_clock::now();
            sum += duration_cast<nanoseconds>(t1 - t0).count();
        }
    }
    double avg = double(sum) / (samples * operations);
    cout << "Sredni czas return_size: " << avg << " ns\n";
}
