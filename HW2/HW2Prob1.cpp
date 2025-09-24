#include <iostream>
#include <string>
using namespace std;
class Customer
{
private:
    string name;
    int age;
    string telephone_number;
    int customer_number;
public:
    void setName (string n){name = n;}
    
    string getName() {return name;}


    void setAge (int a){age = a;}

    int getAge(){return age;}

    
    void setTelephone_number (string t){telephone_number = t;}

    string getTelephone_number(){return telephone_number;}


    void setCustomer_number (int c){customer_number = c;}

    int getCustomer_number(){return customer_number;}
};
 class Adult : public Customer
    {
    private:
        const double SAVING_INTREST;
        const double CHECK_INTREST;
        const double CHECK_CHARGE;
        const double OVERDRAFT_PENALTY;
    public:
        
    };
   
    class Senior : public Customer
    {
    private:
        const double SAVING_INTREST;
        const double CHECK_INTREST;
        const double CHECK_CHARGE;
        const double OVERDRAFT_PENALTY;
    public:
        
    };
    
   
    class Student : public Customer
    {
    private:
        const double SAVING_INTREST;
        const double CHECK_INTREST;
        const double CHECK_CHARGE;
        const double OVERDRAFT_PENALTY;
    public:
        
    };



class Account
{
private:
    Customer* customer;
    double balance;
    string account_number;
    Transaction transactions[100];
public:
    void setBalance(double bal){balance=bal;}
    void setCustomer(Customer ct){customer=customer;}


    double getBalance() {return balance;}
    
    
};

class Savings : public Account
    {
    private:
        /* data */
    public:
       void deposit(double amount);
       bool withdrawl(double amount);
    };
    
    class Checking : public Account
    {
        private:

        public:

    };
class Transaction
{
    private:
        int account_number;
        string transaction_type;
        double amount;
        string fees;
    public:
        void process_tran(Account*account);
};

class Bank
{
    private:
        Account accounts[50];

    public:
        void add_account(Account new_account);
        bool make_deposit(string account_number, double amount);
        bool make_withdrawl(string account_number, double amount);
        Account*get_account(string account_number);
};