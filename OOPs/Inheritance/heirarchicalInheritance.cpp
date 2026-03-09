#include<bits/stdc++.h>
using namespace std;
class Person {
    public:
    string name;
    int age;
};
class Student : public Person {
    public:
    int rollno;
};
class Teacher : public Person{
    public:
    int salary;
};
int main() {
    Student s;
    s.name="Vivek";
    s.rollno=80;
    Teacher t;
    t.salary=908;
    cout << s.name << endl;
    cout << t.salary << endl;
    return 0;
}