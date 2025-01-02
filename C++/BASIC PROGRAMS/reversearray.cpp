#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    n=4;
    int a[4]={4,3,2,1};
    for(int i=0;i<n;i++){
        for(int j=n-1;j>=0;j--){
            int temp;
            if(i>=j){
                break;
            }
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
    }

    // array after reverse
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    

   return 0; 
}