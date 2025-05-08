#ifndef TEST_H
#define TEST_H

class test {
public:
    // Pomiar czasu operacji insert(e, p)
    static void test_Insert(int size, int num_of_samples, int number_of_operations);

    // Pomiar czasu operacji extract-max()
    static void test_ExtractMax(int size, int num_of_samples, int num_of_operations);

    // Pomiar czasu operacji find-max()/peek()
    static void test_FindMax(int size, int num_of_samples, int num_of_operations);

    // Pomiar czasu operacji modify-key(e, newPriority)
    static void test_ModifyKey(int size, int num_of_samples, int num_of_operations);

    // Pomiar czasu operacji return-size()
    static void test_Size(int size, int num_of_samples, int num_of_operations);
};



#endif //TEST_H
