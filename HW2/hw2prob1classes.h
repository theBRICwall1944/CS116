#include <iostream>
#include <string>
using namespace std;

class Customer{
	private:
		string customerName;
		int customerAge;
		int customerNumber;
		string phoneNumber;
		
	
	public:
		void setCustomerName(string c){
			customerName = c;
		}
		string getCustomerName(){return customerName;}

		void setAge(int a){customerAge = a;}

		int getAge(){return customerAge;}

		void setPhoneNumber(string pNum){phoneNumber=pNum;}

		string getPhoneNUmber(){return phoneNumber;}

		void setCustomerNumber(int cNum){customerNumber=cNum;}

		int getCustomerNumber(){return customerNumber;}
	};

int main(){
	Customer bingus;

	bingus.setAge(50);

	cout << "I am " << bingus.getAge() << " Years old." << endl;
}