#include <iostream>
using namespace std;

class Television {
private:
    int modelNumber;
    int screenSize;
    double price;

public:
    // Default constructor
    Television() {
        modelNumber = 0;
        screenSize = 0;
        price = 0.0;
    }

    // Method to input data
    void input() {
        cout << "Enter model number: ";
        cin >> modelNumber;
        if (cin.fail() || modelNumber > 9999 || modelNumber < 0) {
            cin.clear(); // Clears the error flag
            cin.ignore(10000, '\n'); // Ignores the invalid input
            throw 1; // Throw an exception if model number is invalid
        }

        cout << "Enter screen size (in inches): ";
        cin >> screenSize;
        if (cin.fail() || screenSize < 12 || screenSize > 70) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw 2; // Throw an exception if screen size is invalid
        }

        cout << "Enter price: ";
        cin >> price;
        if (cin.fail() || price < 0 || price > 5000) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw 3; // Throw an exception if price is invalid
        }
    }

    // Method to display data
    void display() {
        cout << "Model Number: " << modelNumber << endl;
        cout << "Screen Size: " << screenSize << " inches" << endl;
        cout << "Price: $" << price << endl;
    }

    // Method to reset data members to zero
    void reset() {
        modelNumber = 0;
        screenSize = 0;
        price = 0.0;
    }
};

int main() {
    Television tv;

    try {
        tv.input();  // Call input method with validation
        cout << "\nTelevision Details:\n";
        tv.display();
    } catch (int e) {
        cout << "\nInvalid input detected! Error code: " << e << endl;
        cout << "Resetting television details to default values.\n";
        tv.reset();
        cout << "\nTelevision Details:\n";
        tv.display();
    }

    return 0;
}
















short Algorithm:
step 1:Define Television Class:

Declare modelNumber, screenSize, and price.
Initialize default values in the constructor.
step 2:Input Method:

Prompt user for modelNumber, screenSize, and price.
Validate inputs and throw exceptions if invalid.
step 3:Display Method:

Display modelNumber, screenSize, and price.
step 4:Reset Method:

Reset data members to default values.
step 5:Main Function:

Input data, handle exceptions, and display details.
step 6:Error Handling:

Catch exceptions and reset data if invalid input occurs.
step 7:Exit Program:

Exit after displaying details or handling errors.