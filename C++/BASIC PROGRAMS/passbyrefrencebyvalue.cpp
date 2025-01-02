#include<bits/stdc++.h>
using namespace std;
void print( int num1){
    num1+=5;
    cout<<"The number1 in the print function is : "<<num1<<endl; // output is 10
}
void display(int &num2){
    num2+=5;
    cout<<"The number2 inside the display function  is : "<<num2<<endl;
}
int main(){
    int num1;
    cout<<"Enter the number 1 "<<endl;
    cin>>num1; // n=5
    print(num1);
    cout<<"The number1 inside the main function  is : "<<num1<<endl; // pass by value so here n is 5
    // pass by refrence 
    int num2;
    cout<<"Enter the number2"<<endl;
    cin>>num2;
    display(num2);
    cout<<"The number2 inside the main function is : "<<num2<<endl;
    return 0;
}