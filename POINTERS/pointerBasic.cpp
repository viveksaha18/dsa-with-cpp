#include<bits/stdc++.h>
using namespace std;

// Pointers : Special variables that store address of other variables.
int main(){
    // Syntax
    int a = 10;
    int* ptr = &a;
    
    cout << ptr << endl;
    cout << *ptr << endl;


    float price = 100.25;
    float* ptr1 = &price;
    cout << ptr1 << endl;
    cout << &price << endl;
    cout << *ptr1 << endl;
    return 0;
}