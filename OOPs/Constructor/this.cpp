#include<bits/stdc++.h>
using namespace std;



class Teacher{
private : 
    double salary;
    
public :
  
    Teacher(){
        cout << "Hi , I am a Non-parameterized Constructor" << endl;
    }


    
    Teacher(string name, string dept){
        this->name = name;
        this->dept = dept;
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
    
    Teacher t1("Vivek", "CSE");
    t1.getInfo();
   
    return 0;
}