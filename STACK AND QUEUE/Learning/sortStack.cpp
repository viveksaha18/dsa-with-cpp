#include<bits/stdc++.h>
using namespace std;

/*
Question : 
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task: 
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.

Constraints:
1<=N<=100

Company Tags
AmazonMicrosoftGoldman SachsIntuitYahooIBMKuliza
Topic Tags
Related Articles
If you are facing any issue on this page. Please let us know.

*/
void checkSortedStack(stack<int>& s){
       vector<int> ans;

    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    std::sort(ans.begin(), ans.end());

   for(int i = 0; i < ans.size(); i++){
       s.push(ans[i]);
   }
}
int main(){
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(1);
    checkSortedStack(st);

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}