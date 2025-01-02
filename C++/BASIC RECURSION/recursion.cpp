#include<bits/stdc++.h>
using namespace std;
int cnt=1;

// without using loop print number from 1 to n
// using recursion 
void print(int n){
    if(cnt>n){
        cout<<"The numbers from one to n are :"<<endl;
        return;
    }
    cout<<cnt<<endl;
    cnt++;
    print(n); // function call itself 
}

// printing numbers without decalring a global variable

// Using backtracking printing numbers from one to n 
void bktrack(int i, int n){
    if(i<1)
    {
        cout<<"The numbers from one to n are by using backtracking  : "<<endl;
        return ;
    }
    bktrack(i-1,n);
    cout<<i<<endl;
}


// Using backtracking printing numbers from n to one 
void bktrack1(int i, int n){
    if(i>n)
    {
        cout<<"The numbers from n to one are by using backtracking  : "<<endl;
        return ;
    }
    bktrack1(i+1,n);
    cout<<i<<endl;
}

void printnum(int i, int n){
    if(i>n){

        cout<<"The numbers from 1 to n are :"<<endl;
        return;
         }
    cout<<i<<endl;
    printnum(i+1,n);
}

// print sum of the number 
void sumofseries(int i, int sum){
    if(i<1){
        cout<<"The sum of the series "<<sum<<endl;
        return ;
    }
    sumofseries(i-1,sum+i);
}
// fibonnaci series 
int fib(int n){
    if(n==0){
    return 0;
    }
    if(n==1){
    return 1;
    }
    int res=fib(n-1)+fib(n-2);
    return res;
}


int main(){
    int n;
    cout<<"Enter the digit : "<<endl;
    cin>>n;
   print(n);
    cout<<endl;

    // one more function to print the numbers 
    printnum(1,n);
    cout<<endl;
    // backtracking function calls
    bktrack(n,n);
    cout<<endl;

    bktrack1(1,n);
    cout<<endl;
    // fuction to print sum of numbers

    sumofseries(n,0);
    
    // fib num 
    int catchfib=fib(n);
    cout<<catchfib<<endl;
    return 0;
}