#ifndef GENERATE_DATA_H
#define GENERATE_DATA_H

#include <cstddef>
#include <vector>

class generateArray {
public:

    static int* generateRandom(std::size_t n);


    static std::vector<int> generateUniqueValues(std::size_t n);
};

#endif
