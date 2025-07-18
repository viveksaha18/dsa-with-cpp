#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 10;
    int* ptr = &a;
    int** ptr1 = &ptr;
    cout << &ptr << " " << ptr1 << endl;
    cout << **ptr1 << endl;


    // * -> Derefrence operator -> value at the address.

    cout << &a << endl;
    cout << *(&a) << endl;
    return 0;
}