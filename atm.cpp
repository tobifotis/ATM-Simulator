#include <iostream>
#include <string>
#include <cstdlib> // for system("cls")

using namespace std;

/*
    Mini Project - ATM
Features I want to implement in this project:
    -> Check Balance
    -> Cash withdraw
    -> User Details
    -> Update Mobile No.
*/

class atm
{
private:
    long int account_No;
    int PIN;
    string name;
    double balance;
    string mobile_No;

public:
    // Setter: This function initializes or updates the member variables
    void setData(long int account_No, int PIN, string name, double balance, string mobile_No)
    {
        this->account_No = account_No;
        this->PIN = PIN;
        this->name = name;
        this->balance = balance;
        this->mobile_No = mobile_No;
    }

    // Getters
    long int getAccountNo()
    {
        return account_No;
    }

    int getPIN()
    {
        return PIN;
    }

    string getName()
    {
        return name;
    }

    double getBalance()
    {
        return balance;
    }

    string getMobile_No()
    {
        return mobile_No;
    }

    // Function to update mobile number
    void updateMobileNo(string mob_prev, string mob_new)
    {
        if (mob_prev == mobile_No)
        {
            mobile_No = mob_new;
            cout << endl
                 << "Successfully Updated Mobile No.";
        }
        else
        {
            cout << endl
                 << "Incorrect Old Mobile No!";
        }

        cout << endl
             << "Press Enter to continue...";
        cin.ignore(); // To ignore the previous newline
        cin.get();    // This waits for the user to press Enter
    }

    // Function to withdraw money from the ATM
    void cashWithDraw(int amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << endl
                 << "Please Collect Your Cash";
            cout << endl
                 << "Available Balance: " << balance;
        }
        else
        {
            cout << endl
                 << "Invalid Input or Insufficient Balance";
        }

        cout << endl
             << "Press Enter to continue...";
        cin.ignore(); // To ignore the previous newline
        cin.get();    // This waits for the user to press Enter
    }
};

// Function to clear the screen for Windows system (using cls)
void clearScreen()
{
    system("cls");
}

int main()
{
    // Enter Account Number and PIN ---> user authentication
    int choice = 0, enterPIN;
    long int enterAccountNo;
    bool loggedIn = false;

    // First User (object)
    atm user1;

    // Set User Details (into object) ---> (Setting Default Data)
    user1.setData(11111111, 1111, "Tobi", 350000.49, "8171111111");

    // Authentication Loop
    while (!loggedIn)
    {
        clearScreen(); // Clear screen

        cout << endl
             << "****Welcome to Tobi's Bank****" << endl;
        cout << endl
             << "Enter Your Account No: "; // Ask user to enter account number
        cin >> enterAccountNo;
        cin.ignore(); // To ignore the leftover newline character from previous input

        cout << endl
             << "Enter PIN: "; // Ask user to enter PIN
        cin >> enterPIN;
        cin.ignore(); // To clear the input buffer

        // Authenticate
        if ((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            loggedIn = true; // Set the login flag to true
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                clearScreen(); // Clear screen for main menu

                // User Interface
                cout << endl
                     << "****Welcome to Tobi's Bank****" << endl;
                cout << endl
                     << "Select Options: ";
                cout << endl
                     << "1. Check Balance";
                cout << endl
                     << "2. Cash Withdraw";
                cout << endl
                     << "3. Show User Details";
                cout << endl
                     << "4. Update Mobile No.";
                cout << endl
                     << "5. Exit" << endl;

                cin >> choice; // Take user's choice
                cin.ignore();  // To clear the newline character from input

                switch (choice)
                {
                case 1:
                    cout << endl
                         << "Your Bank balance is: " << user1.getBalance();
                    cin.ignore(); // To clear the newline character left in the buffer
                    cin.get();    // Wait for Enter
                    break;

                case 2:
                    cout << endl
                         << "Enter amount to withdraw: ";
                    cin >> amount;
                    cin.ignore();               // To clear the newline character
                    user1.cashWithDraw(amount); // Call cashWithDraw Function
                    break;

                case 3:
                    cout << endl
                         << "*** User Details are: ";
                    cout << endl
                         << "-> Account no: " << user1.getAccountNo();
                    cout << endl
                         << "-> Name: " << user1.getName();
                    cout << endl
                         << "-> Balance: " << user1.getBalance();
                    cout << endl
                         << "-> Mobile No: " << user1.getMobile_No();

                    cin.ignore();
                    cin.get(); // Wait for Enter
                    break;

                case 4:
                    cout << endl
                         << "Enter Old Mobile No: ";
                    cin >> oldMobileNo;
                    cin.ignore(); // To clear the newline character

                    cout << endl
                         << "Enter New Mobile No: ";
                    cin >> newMobileNo;
                    cin.ignore(); // To clear the newline character

                    user1.updateMobileNo(oldMobileNo, newMobileNo);
                    break;

                case 5:
                    loggedIn = false; // Exit loop
                    break;

                default:
                    cout << endl
                         << "Enter Valid Data!";
                    break;
                }
            } while (loggedIn); // Loop to keep the user in the menu until they choose to exit
        }
        else
        {
            cout << endl
                 << "Invalid Account No or PIN. Please try again.";
            cin.ignore(); // To clear the buffer
            cin.get();    // Wait for Enter before asking for credentials again
        }
    }

    return 0;
}
