#include<bits/stdc++.h>
using namespace std;
// Inheritance -- When properties and member functions of base class are passed on to the derived class.
// Helps in code reusability.
class Person{
    public:
    string name;
    int age;
    // Person() {
    //     cout << "Parent Class Constructor" << endl;
    // }
    // void parentMethod() {
    //     cout << "This is a method of parent class" << endl;
    // }

    // Parameterized constructor
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};
class Student : public Person{
    public:
    int rollno;
    // Student() {
    //     cout << "Derived Class Constructor"<< endl;
    // }
    Student(string name, int age, int rollno) : Person(name, age) {
        this->rollno = rollno;
    }
    void getInfo() {
        cout << name << " " << age << " " << rollno << endl;
    }
};
int main(){
    Student s("Vivek", 21, 101);
    // s.name = "Vivek";
    // s.age = 21;
    // s.rollno = 101;
    s.getInfo();
    // s.parentMethod();
    
    return 0;
}