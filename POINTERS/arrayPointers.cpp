#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {1,2,3,4,5};
    cout << arr << endl; // arr pointer -> constant pointer 
    int a = 10;
   // arr = &a; // constant gives error 
    cout << *arr << endl;

    cout << *(arr+1)<< endl;
    cout << *(arr+2)<< endl;
    cout << *(arr+3)<< endl;
    cout << *(arr+4)<< endl;
    return 0;
}