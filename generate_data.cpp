#include "generate_data.h"
#include <cstdlib>
#include <ctime>
static bool initialized = false;

int* generateArray::generateRandom(std::size_t n) {
    if (!initialized) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        initialized = true;
    }
    int* arr = new int[n];
    for (std::size_t i = 0; i < n; ++i) {
        arr[i] = std::rand();
    }
    return arr;
}
