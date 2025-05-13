#include "generate_data.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

static bool initialized = false;
static bool shuffle_initialized = false;
/*
int* generateArray::generateRandom(size_t n) {
    if (!initialized) {
        srand(static_cast<unsigned>(time(nullptr)));
        initialized = true;
    }

    int* arr = new int[n];
    for (size_t i = 0; i < n; ++i) {
        arr[i] = rand();
    }

    return arr;
}
*/
vector<int> generateArray::generateUniqueValues(size_t n) {
    if (!shuffle_initialized) {
        srand(static_cast<unsigned>(time(nullptr)));
        shuffle_initialized = true;
    }

    vector<int> values(n);                                  //FISHER-YATES SHUFFLE: generator elementów niepowtarzalnych
    for (size_t i = 0; i < n; ++i) {
        values[i] = static_cast<int>(i);
    }


    for (size_t i = n - 1; i > 0; --i) {
        size_t j = rand() % (i + 1);
        swap(values[i], values[j]);
    }

    return values;
}
