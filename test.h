#ifndef TEST_H
#define TEST_H

/**
 * @brief Klasa testująca operacje na kopcu
 */
class test {
public:
    /// @brief Testuje operację insert(e, p)
    static void test_Insert(int size, int num_of_samples, int number_of_operations);

    /// @brief Testuje operację extract_max()
    static void test_ExtractMax(int size, int num_of_samples, int num_of_operations);

    /// @brief Testuje operację find_max()
    static void test_FindMax(int size, int num_of_samples, int num_of_operations);

    /// @brief Testuje operację modify_key(e, p)
    static void test_ModifyKey(int size, int num_of_samples, int num_of_operations);

    /// @brief Testuje operację return_size()
    static void test_Size(int size, int num_of_samples, int num_of_operations);
};

#endif
