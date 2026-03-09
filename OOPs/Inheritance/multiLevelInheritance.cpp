#include<bits/stdc++.h>
using namespace std;

class Person {
    public:
    string name;
    int age;
};

class Student : public Person{
    public:
    int rollno;
};
class GradStudent : public Student {
    public:
    string researchArea;
    void getInfo() {
        cout << "name: " << name << endl;
        cout << "age: " << age << endl;
        cout << "rollno: " << rollno << endl;
        cout << "researchArea: " << researchArea;
    }
};
int main() {
    GradStudent g;
    g.name="Vivek";
    g.age=21;
    g.rollno=222;
    g.researchArea="Computer Science Data Structures and Algorithms";
    g.getInfo();
    return 0;
}