#include<bits/stdc++.h>
using namespace std;

void changeA(int a){
    a = 20;
}

void changePtr(int* a){
    *a = 20;
}

void changeUsingAlias(int &b){
    b = 20;
}
int main(){
    int a = 10;
      
    changeA(a);
    changePtr(&a);

    cout << "Inside main fnx: " << a << endl;
    cout << "Using Ptr: " << a << endl;

    changeUsingAlias(a);
    cout << "Alias: " << a << endl;
    return 0;
}