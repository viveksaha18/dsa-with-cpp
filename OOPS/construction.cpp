#include<bits/stdc++.h>
using namespace std;
class Teacher{
public :
string dept;
Teacher(){
    cout<<"HI, I am constructor"<<endl;
     dept="computer science";
}
};
int main(){
Teacher t1;// constructor calling 

cout<<t1.dept<<endl;
    return 0;
}
