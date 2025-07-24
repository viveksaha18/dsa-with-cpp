#include<bits/stdc++.h>
using namespace std;


class Teacher{
public :
    string name;
    string dept;
    double salary;

    Teacher(string name, string dept, double salary){
        this->name = name;
        this->dept = dept;
        this->salary = salary;
    }

    Teacher(Teacher &orgObj){
        cout << "Copy custom constructor called ..../" << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->salary = orgObj.salary;
    }

    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "Dept: " << dept << endl;
    }

};
int main(){
    Teacher t1("Vivek","CSE",50000);
    t1.getInfo();
    Teacher t2(t1); // Default Copy construcor
    t2.getInfo();

    return 0;
}