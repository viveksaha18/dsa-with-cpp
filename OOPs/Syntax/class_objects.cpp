#include<bits/stdc++.h>
using namespace std;


// Syntax for creating class
class Teacher{
private : 
    double salary;
    // properties / attributes -> values
public :
    string name;
    string dept;
    string subject;
    

    // methods / member function 
    void changeDept(string newDept){
        dept = newDept;
    }

    // setter
    void setSalary(double s){
        salary = s;
    }
    
    // getter 
    double getSalary(){
        return salary;
    }
};
int main(){
    // Synatax for creating objects 
    Teacher t1;
    t1.name = "Vivek Saha";
    t1.subject = "C++";
    t1.dept = "CSE";
    //t1.salary = 50,000; (Gives error it is a private member we cannot access it) but we can use setter and getter function to access it.
    t1.setSalary(50000);
  

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;
    return 0;
}