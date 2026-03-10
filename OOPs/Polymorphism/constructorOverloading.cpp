#include<bits/stdc++.h>
using namespace std;

class Person {
    public:
    Person() {
        cout << "Default constructor called" << endl;
    }
    Person(string name, int age) {
       cout << name << endl;
       cout << age << endl;
    }
};
int main() {
    Person p("Vivek", 21);
    return 0;
}