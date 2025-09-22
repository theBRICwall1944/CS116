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
   
};
 class Adult : public Customer
    {
    private:
        double SAVING_INTREST;
        double CHECK_INTREST;
        double CHECK_CHARGE;
        double OVERDRAFT_PENALTY;
    public:
        
    };
   
    class Senior : public Customer
    {
    private:
        double SAVING_INTREST;
        double CHECK_INTREST;
        double CHECK_CHARGE;
        double OVERDRAFT_PENALTY;
    public:
        
    };
    
   
    class Student : public Customer
    {
    private:
        double SAVING_INTREST;
        double CHECK_INTREST;
        double CHECK_CHARGE;
        double OVERDRAFT_PENALTY;
    public:
        
    };



class Account
{
private:
    /* data */
public:
    
    
    
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