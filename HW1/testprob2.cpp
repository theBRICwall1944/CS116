#include<iostream>
using namespace std;

int sum;
int prod;
int MAX_VAL = 20;
int next_int = 1;

int main(){
    for (next_int; next_int <= MAX_VAL; next_int++) { 
        if (next_int % 2 == 0) {
            sum += next_int; 
        } 
        else { 
            prod *= next_int; 
        }
    
    cout << next_int << endl;

    }
    return 0;
}