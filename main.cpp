#include "test.h"
#include <iostream>

using namespace std;

/**
 * @brief Program testujący struktury danych
 */

int main() {
    int size, samples, operations;

    // Pobranie parametrów testu od użytkownika
    cout << "Podaj rozmiar struktury: ";
    cin >> size;
    cout << "Podaj liczbe egzemplarzy: ";
    cin >> samples;
    cout << "Podaj liczbe operacji: ";
    cin >> operations;

    int wybor;

    do {
        // Menu wyboru testu
        cout << "\nWYBIERZ METODE BADAWCZA\n";
        cout << "0. Zakoncz program\n";
        cout << "1. insert(e, p)\n";
        cout << "2. extract_max()\n";
        cout << "3. find_max()\n";
        cout << "4. modify_key(e, p)\n";
        cout << "5. return_size()\n";
        cout << "Twoj wybor: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                cout << "BADANIE INSERT\n";
            test::test_Insert(size, samples, operations);
            break;
            case 2:
                cout << "BADANIE EXTRACT_MAX\n";
            test::test_ExtractMax(size, samples, operations);
            break;
            case 3:
                cout << "BADANIE FIND_MAX\n";
            test::test_FindMax(size, samples, operations);
            break;
            case 4:
                cout << "BADANIE MODIFY_KEY\n";
            test::test_ModifyKey(size, samples, operations);
            break;
            case 5:
                cout << "BADANIE RETURN_SIZE\n";
            test::test_Size(size, samples, operations);
            break;
            case 0:
                cout << "Zakonczono program.\n";
            break;
            default:
                cout << "Nieprawidlowy wybor. Sprobuj ponownie.\n";
        }

    } while (wybor != 0);

    return 0;
}
