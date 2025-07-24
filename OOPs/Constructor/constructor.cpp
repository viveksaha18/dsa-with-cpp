#include<bits/stdc++.h>
using namespace std;


// Syntax for creating class
class Teacher{
private : 
    double salary;
    // properties / attributes -> values
public :
    // Non-parameterized Constructor
    Teacher(){
        cout << "Hi , I am a Non-parameterized Constructor" << endl;
    }


    // Parameterized Constructor
    Teacher(string n, string d){
        name = n;
        dept = d;
        cout << "Parameterized Constructor called" << endl;
    }

    
    string name;
    string dept;
    string subject;
    
    void getInfo(){
        cout << "Name :" << name << endl;
        cout << "Department :" << dept << endl;
    }

 
   
};
int main(){
    // Synatax for creating objects 
    Teacher t1("Vivek", "CSE");
    t1.getInfo();
    Teacher t2; // Non-parameterized constructor called
   
    return 0;
}