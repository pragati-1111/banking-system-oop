// Class & Object
// Polymorphism
// Inheritance
// Encapsulation

#include <iostream>
using namespace std;

class BankAccount
{


public:
    double balance = 0;
    int accountNumber;
    string accountHolderName;

public:
    void getInfo()
    {
        cout << "Enter your Account number:= ";
        cin >> accountNumber;
        cout << "Enter your Account holder name:=";
        cin >> accountHolderName;
    }
    double deposit(double amount)
    {
        balance += amount;
        return balance;
    }

    double withdraw(double amount)
    {
        if (amount > balance)
        {
          cout << "Insufficient balance. Please deposit funds before withdrawing." << endl;

        }else{
            balance -= amount;
        }
        return balance;
    }

    double getBalance()
    {
        return balance;
    }

    void displayAccountInfo()
    {
        cout << "Account number is:= " << accountNumber << endl;
        cout << "Account holder name is:= " << accountHolderName << endl;
        cout << "Current balance is:= " << balance << endl;
    }
};

class SavingsAccount : public BankAccount
{
    public:
    double interestRate=0;
    double calculateInterest()
    {
        double time, interest=0;
        double rate;
        cout << "how many interest you want to put apply.(in percentage): ";
        cin >> rate;
        cout << "How many year you want to put on interest.: ";
        cin >> time;
        double current = balance;
        int i=0;

        while(i<time){
             double yearlyInterest;
            yearlyInterest = (current * rate) / 100;
            interest += yearlyInterest;
            current += yearlyInterest;
            i++;
        }


        interest = current - balance;
    
        cout << "Final amount after " << time << " years with compounding: " << current << endl;
        return interest;
    }
};

class CheckingAccount : public BankAccount
{
    public:
    double overdraftLimit;
    CheckingAccount() {
        overdraftLimit = 10000; 
    }
    double withdraw(double amount) {
        if ((balance - amount) < -overdraftLimit) {
            cout << "Transaction failed! Withdrawal exceeds overdraft limit." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
        return balance;
    }

    
    void checkOverdraft() {
        if (balance < 0) {
            cout << " Overdraft used:= " << -balance << endl;
            cout << "Remaining overdraft limit:=" << overdraftLimit + balance << endl;
        } else {
            cout << "Your current balance is:=" << balance <<"....."<< endl;
        }
    }
};

class FixedDepositAccount : public BankAccount
{
    public:
    double time, interestRate, money;
    double calculateInterest() {
        cout << "Enter amount for calaculate interest:=";
        cin >> money;
        cout << "Enter term in month: ";
        cin >> time;
        cout << "Enter interest rate (%): ";
        cin >> interestRate;

        double present_balance = money;

        for (int i = 0; i < time; i++)
        {
          double monthlyInterest = (present_balance * (interestRate / 12)) / 100;

            present_balance += monthlyInterest;
        }

        double totalInterest = present_balance - money;

        cout << "Final amount in " << time << " month : " << present_balance << endl;
        return totalInterest;
    }
};

int main()
{
    BankAccount bank1;
    SavingsAccount saving1;
    CheckingAccount check1;
    FixedDepositAccount fixed1;
    int choice;
    int accountNumber;
    string accountHolderName;
    do
    {
        cout << "press 1 for create savings account." << endl;
        cout << "press 2 for create checking account." << endl;
        cout << "press 3 for create fixed deposit account." << endl;
        cout << "press 0 for exit." << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            saving1.getInfo();
            cout << "Dear user!! your savings account has been created successfully...." << endl;
            int choice1;
            do
            {
                
                cout << "press 1 for deposit." << endl;
                cout << "press 2 for withdraw." << endl;
                cout << "press 3 for display balance." << endl;
                cout << "press 4 for display account information." << endl;
                cout << "press 5 for calculate inbterest on balance." << endl;
                cout << "press 0 for exit......" << endl;
                cin >>choice1;
                switch (choice1)
                {
                case 1:
                {
                    double amount;
                    cout << "Enter amount for deposit: ";
                    cin >> amount;
                    double blnc = saving1.deposit(amount);
                    cout << "your balance is successfully deposit." << endl;
                    break;
                }

                case 2:
                {
                    double amount;
                    cout << "Enter amount for withdraw: ";
                    cin >> amount;
                    double blnc = saving1.withdraw(amount);
                    cout << "your balance is successfully withdraw....." << endl;
                    break;
                }

                case 3:
                {
                    double display = saving1.getBalance();
                    cout << "Your current balance is: " << display << endl;
                    break;
                }

                case 4:
                {
                    saving1.displayAccountInfo();
                    break;
                }

                case 5:
                {
                    
                    double interest = saving1.calculateInterest();
                    cout << " interest rate is: " << interest << endl;
                    break;
                }

                default:
                    cout << "Thank you for using our services ...." << endl;
                }
            } while (choice1!= 0);
            break;
        }

        case 2:
        {
            check1.getInfo();
            cout << "Dear user!!! your checking account has been created successfully." << endl;
            int choice2;
            do
            {
                
                cout << "press 1 for deposit." << endl;
                cout << "press 2 for withdraw." << endl;
                cout << "press 3 for display balance." << endl;
                cout << "press 4 for display account info." << endl;
                cout << "press 5 for check overdraft limit." << endl;
                cout << "press 0 for exit." << endl;
                cin >> choice2;
                switch (choice2)
                {
                case 1:
                {
                    double amount;
                    cout << "Enter amount for deposit: ";
                    cin >> amount;
                    double blnc = check1.deposit(amount);
                    cout << "your balance is successfully deposit." << endl;
                    break;
                }

                case 2:
                {
                    double amount;
                    cout << "Enter amount for withdraw: ";
                    cin >> amount;
                    double blnc = check1.withdraw(amount);
                    cout << "your balance is successfully withdraw." << endl;
                    break;
                }

                case 3:
                {
                    double display = check1.getBalance();
                    cout << "Your current balance is: " << display << endl;
                    break;
                }

                case 4:
                {
                    check1.displayAccountInfo();
                    break;
                }

                case 5:
                {
                    
                    check1.checkOverdraft();
                    break;
                }

           

                default:
                    cout << "Thank you for using our services and bank." << endl;
                }
            } while (choice2 != 0);
            break;
        }
        
        case 3:
        {
            fixed1.getInfo();
            cout << "Dear user!!! your checking account has been created successfully." << endl;
            int choice3;
            do
            {
                
                cout << "press 1 for deposit." << endl;
                cout << "press 2 for withdraw." << endl;
                cout << "press 3 for display balance." << endl;
                cout << "press 4 for display account info." << endl;
                cout << "press 5 for calculate interest on fixeddeposit account." << endl;
                cout << "press 0 for exit." << endl;
                cin >> choice3;
                switch (choice3)
                {
                case 1:
                {
                    double amount;
                    cout << "Enter amount for deposit: ";
                    cin >> amount;
                    double blnc = fixed1.deposit(amount);
                    cout << "your balance is successfully deposit." << endl;
                    break;
                }

                case 2:
                {
                    double amount;
                    cout << "Enter amount for withdraw: ";
                    cin >> amount;
                    double blnc = fixed1.withdraw(amount);
                    cout << "your balance is successfully withdraw." << endl;
                    break;
                }

                case 3:
                {
                    double display = fixed1.getBalance();
                    cout << "Your current balance is: " << display << endl;
                    break;
                }

                case 4:
                {
                    fixed1.displayAccountInfo();
                    break;
                }

                case 5:
                {
                    
                    double fix_interest = fixed1.calculateInterest();
                    cout << "Your interest on fixed deposit account is: " << fix_interest << endl;
                    break;
                }


                default:
                    cout << "Thank you for using our services and bank." << endl;
                }
            } while (choice3 != 0);
            break;
        }
        }


    } while (choice!= 0);
    return 0;
}

