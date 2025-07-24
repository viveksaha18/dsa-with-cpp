#include<bits/stdc++.h>
using namespace std;

class Student {
    public :
    string name;
    string branch;
// Opposite of constructor destroys the object
    ~Student() {
        cout << "Deconstructor called" << endl;
    }

};
int main(){
    Student s1;
    return 0;
}