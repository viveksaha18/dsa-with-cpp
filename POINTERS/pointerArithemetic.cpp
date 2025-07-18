#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 10;
    int* ptr = &a;

    cout << ptr << endl;
    ptr++;
    cout << ptr << endl;
    ptr = ptr +2;// 2int

    
    // allowed (int) ptr1 - ptr2(int) addition not allowed 108 - 100 = 8bytes so 2 int can be stored it will return 2

    int* sub;
    int* sub1 = sub + 2;
    cout << sub1 - sub << endl; // answer will be 2
    return 0;
}