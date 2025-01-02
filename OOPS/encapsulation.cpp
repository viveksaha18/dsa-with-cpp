#include<bits/stdc++.h>
using namespace std;
 class Teacher {
    private : 
    double salary;
    public :
// properties 
string name;
string dept;
string subjects;
// methods
void changeDept(string newdept){
    dept=newdept;
    cout<<dept<<endl;
}
void setsalary( double s){
    salary=s;
}
double getsalary(){
    return salary;
}
};
class Student
{
    public :
    string name;
    int rollno;
    int registrationnumber;
};
class Accout{
    private : 
    double balance;
    string password;
    public : 
    string username;
    string accountid;
};
int main(){
    Teacher T1;
T1.name="Vivek";
cout<<T1.name;
T1.changeDept("CSE");
T1.setsalary(25000);
int x=T1.getsalary();
cout<<x;
cout<<endl;
Student t1;
t1.name="Vivek";
t1.rollno=41;
cout<<t1.name<<endl;
cout<<t1.rollno;
return 0;
}