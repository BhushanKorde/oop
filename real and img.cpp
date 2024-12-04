#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float real_part;
    float imaginary_part;

public:
    // Default constructor
    Complex() {
        real_part = 0.0;
        imaginary_part = 0.0;
    }

    // Parameterized constructor
    Complex(float real_part, float imaginary_part) {
        this->real_part = real_part;
        this->imaginary_part = imaginary_part;
    }

    // Overloading '+' operator
    Complex operator+(Complex &second_operand) {
        Complex answer;
        answer.real_part = real_part + second_operand.real_part;
        answer.imaginary_part = imaginary_part + second_operand.imaginary_part;
        return answer;
    }

    // Overloading '*' operator
    Complex operator*(Complex &second_operand) {
        Complex answer;
        answer.real_part = real_part * second_operand.real_part - imaginary_part * second_operand.imaginary_part;
        answer.imaginary_part = real_part * second_operand.imaginary_part + imaginary_part * second_operand.real_part;
        return answer;
    }

    // Overloading '-' operator
    Complex operator-(Complex &second_operand) {
        Complex answer;
        answer.real_part = real_part - second_operand.real_part;
        answer.imaginary_part = imaginary_part - second_operand.imaginary_part;
        return answer;
    }

    // Overloading '/' operator
    Complex operator/(Complex &second_operand) {
        Complex answer;
        float denominator = pow(second_operand.real_part, 2.0) + pow(second_operand.imaginary_part, 2.0);
        if (denominator == 0) {
            cout << "Error: Division by zero is not allowed.\n";
            answer.real_part = 0;
            answer.imaginary_part = 0;
        } else {
            answer.real_part = (real_part * second_operand.real_part + imaginary_part * second_operand.imaginary_part) / denominator;
            answer.imaginary_part = (imaginary_part * second_operand.real_part - real_part * second_operand.imaginary_part) / denominator;
        }
        return answer;
    }

    // Function to display complex number
    void show() {
        if (imaginary_part >= 0)
            cout << real_part << " + " << imaginary_part << "i" << endl;
        else
            cout << real_part << " - " << fabs(imaginary_part) << "i" << endl;
    }
};

int main() {
    float real_part, real_part_2, imaginary_part_2, imaginary_part;

    cout << "Enter Real Part Of the Complex Number 1: ";
    cin >> real_part;
    cout << "Enter Imaginary Part Of the Complex Number 1: ";
    cin >> imaginary_part;
    cout << "Enter Real Part Of the Complex Number 2: ";
    cin >> real_part_2;
    cout << "Enter Imaginary Part Of the Complex Number 2: ";
    cin >> imaginary_part_2;

    Complex x = Complex(real_part, imaginary_part);
    Complex y = Complex(real_part_2, imaginary_part_2);

    int choice;
    Complex z;

    do {
        cout << "\nOperation Menu:" << endl;
        cout << "1. Add Complex Numbers" << endl;
        cout << "2. Subtract Complex Numbers" << endl;
        cout << "3. Multiply Complex Numbers" << endl;
        cout << "4. Divide Complex Numbers" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                z = x + y;
                z.show();
                break;
            case 2:
                z = x - y;
                z.show();
                break;
            case 3:
                z = x * y;
                z.show();
                break;
            case 4:
                z = x / y;
                z.show();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
