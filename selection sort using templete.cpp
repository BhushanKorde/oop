#include <iostream>
using namespace std;

template <typename T>
void sortarray(T a[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (a[i] > a[j]) {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

template <typename T>
void displayarray(T a[], int size) {
    for (int i = 0; i < size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;

    // Sorting integers
    cout << "Enter the number of integer elements: ";
    cin >> size;
    int intarray[size];
    cout << "Enter " << size << " integer elements: ";
    for (int i = 0; i < size; i++) {
        cin >> intarray[i];
    }
    sortarray(intarray, size);
    cout << "Sorted integers: ";
    displayarray(intarray, size);

    // Sorting doubles
    cout << "\nEnter the number of double elements: ";
    cin >> size;
    double doublearray[size];
    cout << "Enter " << size << " double elements: ";
    for (int i = 0; i < size; i++) {
        cin >> doublearray[i];
    }
    sortarray(doublearray, size);
    cout << "Sorted doubles: ";
    displayarray(doublearray, size);

    // Sorting characters
    cout << "\nEnter the number of character elements: ";
    cin >> size;
    char chararray[size];
    cout << "Enter " << size << " character elements: ";
    for (int i = 0; i < size; i++) {
        cin >> chararray[i];
    }
    sortarray(chararray, size);
    cout << "Sorted characters: ";
    displayarray(chararray, size);

    return 0;
}
