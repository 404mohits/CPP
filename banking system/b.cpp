#include <iostream>
#include <string>
using namespace std;

class bankAccount
{
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    bankAccount(string accNum, string accHolder, double initialBalance)
    {
        accountNumber = accNum;
        accountHolder = accHolder;
        balance = initialBalance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrew: " << amount << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
        }
    }

    double getBalance()
    {
        return balance;
    }

    void displayAccountInfo()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << getBalance() << endl;
        cout << "-----------------------------" << endl;
    }
};

class SavingsAccount : public bankAccount
{
private:
    double interestRate;

public:
    SavingsAccount(string accNum, string accHolder, double initialBalance, double rate) : bankAccount(accNum, accHolder, initialBalance)
    {
        interestRate = rate;
    }

    void calculateInterest()
    {
        double interest = getBalance() * interestRate;
        deposit(interest);
    };
    void displayAccountInfo()
    {
        bankAccount::displayAccountInfo();
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "-----------------------------" << endl;
    }
    void checkBalance()
    {
        cout << "Savings Account Balance: $" << getBalance() << endl;
        cout << "-----------------------------" << endl;
    }
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= getBalance())
        {
            bankAccount::withdraw(amount);
            cout << "-----------------------------" << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient funds." << endl;
            cout << "-----------------------------" << endl;
        }
    }
    void deposit(double amount)
    {
        if (amount > 0)
        {
            bankAccount::deposit(amount);
            cout << "-----------------------------" << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
            cout << "-----------------------------" << endl;
        }
    }
};
    class CheckingAccount : public bankAccount
    {
    private:
        double overdraftLimit;

    public:
        CheckingAccount(string accNum, string accHolder, double initialBalance, double overdraft) : bankAccount(accNum, accHolder, initialBalance)
        {
            overdraftLimit = overdraft;
        }

        void displayAccountInfo()
        {
            bankAccount::displayAccountInfo();
            cout << "Overdraft Limit: $" << overdraftLimit << endl;
            cout << "-----------------------------" << endl;
        }
        void checkBalance()
        {
            cout << "Checking Account Balance: $" << getBalance() << endl;
            cout << "-----------------------------" << endl;
        }
        void withdraw(double amount)
        {
            if (amount > 0 && amount <= getBalance() + overdraftLimit)
            {
                bankAccount::withdraw(amount);
                cout << "-----------------------------" << endl;
            }
            else
            {
                cout << "Invalid withdrawal amount or insufficient funds." << endl;
                cout << "-----------------------------" << endl;
            }
        }
        void deposit(double amount)
        {
            if (amount > 0)
            {
                bankAccount::deposit(amount);
                cout << "-----------------------------" << endl;
            }
            else
            {
                cout << "Invalid deposit amount." << endl;
                cout << "-----------------------------" << endl;
            }
        }
    };

        class fixedDepositAccount : public bankAccount
        {
        private:
            double interestRate;
            int maturityPeriod; // in months
        public:
            fixedDepositAccount(string accNum, string accHolder, double initialBalance, double rate, int maturity) : bankAccount(accNum, accHolder, initialBalance)
            {
                interestRate = rate;
                maturityPeriod = maturity;
            }
            void calculateInterest()
            {
                double interest = getBalance() * interestRate * (maturityPeriod / 12.0);
                deposit(interest);
            }
            void displayAccountInfo()
            {
                bankAccount::displayAccountInfo();
                cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
                cout << "Maturity Period: " << maturityPeriod << " months" << endl;
                cout << "-----------------------------" << endl;
            }
            void checkBalance()
            {
                cout << "Fixed Deposit Account Balance: $" << getBalance() << endl;
                cout << "-----------------------------" << endl;
            }
            void withdraw(double amount)
            {
                cout << "Withdrawals are not allowed from a fixed deposit account before maturity." << endl;
                cout << "-----------------------------" << endl;
            }
            void deposit(double amount)
            {
                cout << "Deposits are not allowed into a fixed deposit account after initial deposit." << endl;
                cout << "-----------------------------" << endl;
            }
        };

        int main()
        {
            SavingsAccount myAccount("123456789", "rohan pandit", 1000.0, 0.05);
            myAccount.displayAccountInfo();
            myAccount.calculateInterest();

            myAccount.deposit(500.0);
            myAccount.withdraw(200.0);
            myAccount.displayAccountInfo();

            CheckingAccount myChecking("987654321", "prince chauhan", 500.0, 200.0);
            myChecking.displayAccountInfo();
            myChecking.deposit(300.0);
            myChecking.withdraw(600.0);
            myChecking.displayAccountInfo();

            fixedDepositAccount myFixedDeposit("555555555", "mohit singh", 2000.0, 0.04, 12);
            myFixedDeposit.displayAccountInfo();
            myFixedDeposit.calculateInterest();
            myFixedDeposit.displayAccountInfo();
            myFixedDeposit.withdraw(500.0);
            myFixedDeposit.deposit(500.0);

            return 0;
        };
