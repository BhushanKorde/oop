#include <iostream>
#include <iomanip> // for formatting output
using namespace std;

class bank
{
public:
    string name;
    int acc_no;
    int current_amount;
    int deposit_amount;
    int withdraw_amount;

    void accept()
    {
        cout << "\nEnter Account Holder Name: ";
        cin >> name;
        cout << "Enter Account Number: ";
        cin >> acc_no;
        cout << "Enter Current Balance: ";
        cin >> current_amount;
        cout << "\n--- Account Information Recorded Successfully ---\n";
    }

    void display()
    {
        cout << "\n--- Account Details ---";
        cout << "\nName           : " << name;
        cout << "\nAccount Number : " << acc_no;
        cout << "\nCurrent Balance: " << current_amount << "\n";
    }

    void deposit()
    {
        cout << "\nEnter Deposit Amount: ";
        cin >> deposit_amount;
        current_amount += deposit_amount;
        cout << "\n--- Deposit Successful ---";
        cout << "\nUpdated Balance: " << current_amount << "\n";
    }

    void withdraw()
    {
        cout << "\nEnter Withdraw Amount: ";
        cin >> withdraw_amount;

        if (withdraw_amount > current_amount)
        {
            cout << "\n--- Withdrawal Failed: Insufficient Balance ---\n";
        }
        else
        {
            current_amount -= withdraw_amount;
            cout << "\n--- Withdrawal Successful ---";
            cout << "\nUpdated Balance: " << current_amount << "\n";
        }
    }
};

int main()
{
    int a, i, ch, size;
    bank obj[20];

    cout << "\n--- Welcome to the Banking System ---\n";
    cout << "Enter the Number of Customers: ";
    cin >> size;

    do
    {
        cout << "\n--- Main Menu ---";
        cout << "\n1. Accept Information";
        cout << "\n2. Display Information";
        cout << "\n3. Deposit Amount";
        cout << "\n4. Withdraw Amount";
        cout << "\n5. Exit";
        cout << "\nSelect an Option: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            for (i = 0; i < size; i++)
            {
                cout << "\nEntering Details for Customer " << i + 1 << ":";
                obj[i].accept();
            }
            break;

        case 2:
            cout << "\n--- Displaying All Customer Information ---\n";
            for (i = 0; i < size; i++)
            {
                obj[i].display();
            }
            break;

        case 3:
            cout << "\nEnter Account Number for Deposit: ";
            cin >> a;
            for (i = 0; i < size; i++)
            {
                if (obj[i].acc_no == a)
                {
                    obj[i].deposit();
                    break;
                }
            }
            if (i == size)
            {
                cout << "\n--- Invalid Account Number ---\n";
            }
            break;

        case 4:
            cout << "\nEnter Account Number for Withdrawal: ";
            cin >> a;
            for (i = 0; i < size; i++)
            {
                if (obj[i].acc_no == a)
                {
                    obj[i].withdraw();
                    break;
                }
            }
            if (i == size)
            {
                cout << "\n--- Invalid Account Number ---\n";
            }
            break;

        case 5:
            cout << "\n--- Thank You for Using the Banking System. Goodbye! ---\n";
            break;

        default:
            cout << "\n--- Invalid Choice! Please Try Again. ---\n";
            break;
        }
    } while (ch != 5);

    return 0;
}




















Algorithm:
Step 1: Start the program

Initialize the banking system.
Step 2: Input the number of customers (size)

Ask the user to input the number of customers for which the banking details will be entered.
Step 3: Display the main menu

Show the following options to the user:
Accept Information
Display Information
Deposit Amount
Withdraw Amount
Exit
Step 4: Accept Information

For each customer, input their name, account number, and current balance.
Store this information in an array of bank account objects.
Step 5: Display Information

Display the details (name, account number, current balance) of all customers.
Step 6: Deposit/Withdraw Amount

For deposit, input the account number, deposit amount, and update the balance.
For withdrawal, input the account number, withdrawal amount, check balance, and update if sufficient.
Step 7: Exit the program