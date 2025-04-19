#include<bits/stdc++.h>
using namespace std;

void printSubset1(vector<int>& arr, vector<int>& ans,int i ){
    if(i == arr.size()){
        for(int it : ans){
            cout << it;
        }
        cout << endl;
        return ;
    }

    // include
    ans.push_back(arr[i]);
    printSubset1(arr,ans,i+1);

    //exclude
    ans.pop_back();
    printSubset1(arr,ans,i+1);
}
int main(){

    /* set a = {1,2,3}

    subset are from set a {{1},{1,2},{1,3},{1,2,3},{2},{2,3},{3}}
    */

    // We use recurssion to solve this particular problem 
    /*

    In recurrsion we are keeping solving on small parts of problem which eventually solve the bigger problem .

    So if i have only one element then what should be it subset 
    like if have a set a = [1] so its subset are [1] []
    
    Basically what are doing at first i include 1 and then i exclude it 

    */


    vector<int> arr = {1,2,3};
    vector<int> ans;
    printSubset1(arr,ans,0);
    return 0;
}