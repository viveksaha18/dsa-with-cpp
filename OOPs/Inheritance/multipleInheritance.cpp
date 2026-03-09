#include<bits/stdc++.h>
using namespace std;
class Person{
    public:
    string name;
    int age;
};

class Teacher {
    public:
    string subject;
    int salary;
};
class TA : public Teacher, public Person {

};
int main() {
    TA t1;
    t1.name="Vivek";
    t1.subject="DS";
    cout << t1.name;
    cout << endl;
    cout << t1.subject;
    return 0;
}