#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

struct CUSTOMER_DETAILS {
    string username;
    int password;
    float deposit_amount;
    float balance;
    float withdrawl_amount;
};

void create_account(CUSTOMER_DETAILS &user);
int Account_verification(CUSTOMER_DETAILS &user);
void deposit(CUSTOMER_DETAILS &user);
void withdrawl(CUSTOMER_DETAILS &user);

int main()
{
    CUSTOMER_DETAILS user;
    char choice;
    char choice2;
    bool exitProgram = false; 

    cout << endl;
    cout << "Welcome to Bank XYZ ATM" << endl;
    cout << "***************************" << endl;

    do
    {
        cout << endl << "Please select an option from the menu below: \n l -> Login \n c -> Create New Account \n q -> Quit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 'l':
            {
                if (Account_verification(user) == 1)
                {
                    cout << "Acess granted!" << endl;
                    fstream trans_history;
                    trans_history.open("trans_history.txt", ios::out | ios::app);
                    trans_history << "Acess granted!" << endl;
                    trans_history.close();

                    do
                    {
                        cout << endl << " d -> Deposit Money \n w -> Withdraw Money \n r -> Request Balance \n q -> Exit";
                        cout << endl;
                        cin >> choice2;

                        switch (choice2)
                        {
                            case 'd':
                                deposit(user);
                                break;

                            case 'w':
                                withdrawl(user);
                                break;

                            case 'r':
                                cout << endl << "Your Current balance is : ";
                                cout << user.balance;
                                cout << endl;
                                trans_history.open("trans_history.txt", ios::out | ios::app);
                                trans_history << endl << "Your Current balance is : ";
                                trans_history << user.balance << endl;
                                break;

                            default:
                                exitProgram = true; 
                        }
                    }
                    while ((choice2 == 'd' || choice2 == 'w' || choice2 == 'r') && !exitProgram);
                }
                else
                {
                    cout << "******* LOGIN FAILED *******" << endl;
                    fstream trans_history;
                    trans_history.open("trans_history.txt", ios::out | ios::app);
                    trans_history << "******* LOGIN FAILED *******" << endl;
                    trans_history.close();
                }

                break;
            }

            case 'c':
            {
            	cout << endl;
                create_account(user);
            }
        }
    }
    while ((choice == 'l' || choice == 'c') && !exitProgram);

    cout << endl << "Thankyou! come again \n*****************" <<endl;
    fstream trans_history;
    trans_history.open("trans_history.txt", ios::out | ios::app);
    trans_history << endl << "Thankyou! come again \n*****************" <<endl;
    trans_history.close();
}

void create_account(CUSTOMER_DETAILS &user)
{
    fstream trans_history;
    trans_history.open("trans_history.txt", ios::out | ios::app);
    cout << "Enter a username : " << endl;
    cin >> user.username;
    trans_history <<endl << "User name : " << user.username << endl;
    cout << "Enter a Password : " << endl;
    cin >> user.password;
    trans_history << "Password : " << user.password << endl;
    cout << "Congrats! Your account is created" << endl;
    trans_history << "Congrats! Your account is created" << endl;
    trans_history.close();
}

int Account_verification(CUSTOMER_DETAILS &user)
{
    int input_password;
    string input_username;
    cout << "Enter username : " << endl;
    cin >> input_username;
    cout << "Enter password : " << endl;
    cin >> input_password;
    if (input_username == user.username && input_password == user.password)
        return 1;
    else
        return 0;
}

void deposit(CUSTOMER_DETAILS &user)
{
    fstream trans_history;
    trans_history.open("trans_history.txt", ios::out | ios::app);
    cout << endl << "Amount of deposit : ";
    trans_history << endl << "Amount of deposit : ";
    cin >> user.deposit_amount;
    trans_history << user.deposit_amount << endl;
    user.balance = user.balance + user.deposit_amount;
    trans_history << "Current Balance : " << user.balance << endl;
    trans_history.close();
}

void withdrawl(CUSTOMER_DETAILS &user)
{
    fstream trans_history;
    trans_history.open("trans_history.txt", ios::out | ios::app);
    cout << "Amount of Withdrawl : " << endl;
    trans_history << "Amount of Withdrawl : ";
    cin >> user.withdrawl_amount;
    trans_history << user.withdrawl_amount << endl ;
    user.balance = user.balance - user.withdrawl_amount;
    trans_history << "Current Balance : " << user.balance << endl;
    trans_history.close();
}
