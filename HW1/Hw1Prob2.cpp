#include<iostream>
using namespace std;

int MAX_VAL = 5;
int sum;
int prod;
int next_int = 1;

int main(){

    do {
        
        if (next_int % 2 == 0) {
                sum += next_int; 
            } 
            else { 
                prod *= next_int; 
            }
        next_int++;
        cout << next_int << endl;

    } 
    while (next_int < MAX_VAL);
    
}