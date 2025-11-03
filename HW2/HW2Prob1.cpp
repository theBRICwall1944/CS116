#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
class Customer
{
private:
    string name;
    int age;
    string telephone_number;
    int customer_number;
public:
   Customer(string n, int a, string t, int c):
   name(n), age(a),  telephone_number(t), customer_number(c) {}
    
    string getName() {return name;}
    virtual ~Customer(){}
};
 class Adult : public Customer
    {
    protected:
        const double SAVING_INTREST = 0.035;
        const double CHECK_INTREST=0.03;
        const double CHECK_CHARGE=0.009;
        const double OVERDRAFT_PENALTY = 0.005;
    public:
        Adult(string n, int a, string t, int c)
        :Customer(n,a,t,c) {}
    };
   
    class Senior : public Customer
    {
    protected:
        const double SAVING_INTREST = 0.5;
        const double CHECK_INTREST = 0.4;
        
    public:
        const double CHECK_CHARGE = 0.02;
        const double OVERDRAFT_PENALTY = 0.01;
       
        Senior(string n, int a, string t, int c)
       : Customer(n,a,t,c) {}
    };
    
   
    class Student : public Customer
    {
    protected:
        const double SAVING_INTREST = 0.08;
        const double CHECK_INTREST = 0.07;
        const double CHECK_CHARGE = 0.003;
        const double OVERDRAFT_PENALTY = 0;
    public:
        Student(string n, int a, string t, int c)
        : Customer(n,a,t,c){}
    };



class Account
{
protected:
    Customer* customer;
    double balance;
    string account_number;
public:
    Account(Customer *ctr, string accountNum, double bal):
    customer(ctr), account_number(accountNum), balance(bal) {}

    virtual ~Account(){}
    virtual void deposit(double count) = 0;
    virtual bool withdraw(double count) = 0;

    double getBalance() {return balance;}
    string getAccountNumber() const {return account_number;}
    
    
};

class Savings : public Account
    {
    private:
        /* data */
    public:
       Savings(Customer *ctr, string accountNum, double bal)
        :Account(ctr, accountNum, bal){}

        void deposit(double count) override{
            if (count > 0) balance += count; 
        }

        bool withdraw(double count) override{
            if (count >0 && balance <= count) {
                balance -= count;
                return true;
            }
            return false;
        }
    };
    
    class Checking : public Account
    {
        protected:
            double CHECK_CHARGE;
            double OVERDRAFT_PENTALTY;
        public:
            Checking(Customer* ctr, string accountNum, double bal)
                : Account(ctr,accountNum,bal){
                if (Student* st = dynamic_cast<Student*>(ctr)){
                    CHECK_CHARGE = st -> CHECK_CHARGE;
                    OVERDRAFT_PENALTY = st -> OVERDRAFT_PENALTY;
                }
                else if (Adult* ad = dynamic_cast<Adult*>(ctr)){
                    CHECK_CHARGE  = ad -> CHECK_CHARGE
                }

    };
class Transaction
{
    private:
        int account_number;
        string transaction_type;
        double amount;
        string fees;
    public:
        Transaction(string type, double amt) : transaction_type(type), amount (amt) {}

        void process_tran(Account*account){
            if (!account)return;
            if (transaction_type == "Deposit") account -> deposit(amount);
            else if (transaction_type == "Withdraw") account -> withdraw(amount);
        }
};

class Bank
{
    private:
        Account accounts[50];
        int numberOfAccounts;
    public:
        Bank(): numberOfAccounts(0){
            for (int i = 0; i < 50; i++) delete accounts[i];
        }

        void makeAccount(Account* accounts) {
            if (numberOfAccounts < 50) {
                this -> accounts[numberOfAccounts++] == accounts;
            }
        }

        Account* get_account(string account_number){{
            for (int i = 0; i < numberOfAccounts; i++){
                if (accounts[i] -> getAccountNumber() == account_number)
                return accounts[i];
            }
            return nullptr;
        }

        void display_accounts() const {
            for (int i = 0; i < numberOfAccounts; i++){
                cout << accounts[i]->to_string() << endl;
            }
        }
};