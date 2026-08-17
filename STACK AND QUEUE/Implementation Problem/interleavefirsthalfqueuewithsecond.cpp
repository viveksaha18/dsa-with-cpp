#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        
        queue<int> firstHalf, secondHalf;
        
        int n = q.size();
        
        for(int i = 0; i < n/2; i++) {
            firstHalf.push(q.front());
            q.pop();
        }
        
        while(!q.empty()) {
            secondHalf.push(q.front());
            q.pop();
        }
        
        while(!firstHalf.empty() && !secondHalf.empty()) {
            q.push(firstHalf.front());
            firstHalf.pop();
            q.push(secondHalf.front());
            secondHalf.pop();
        }
        
        
        
    }
};

int main() {
    Solution s;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    s.rearrangeQueue(q);
    return 0;
}