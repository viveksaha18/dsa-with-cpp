#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int p1steps = 0 , p2steps = 0;

        if(x > z){
            for(int i = x; i >=z; i--){
                 p1steps++;
            }
        }
        else{
        for(int i = x; i <=z; i++){
            p1steps++;
        }
        }
        if(y > z){
            for(int i = y; i >=z; i--){
                 p2steps++;
            }
            
        }

        else{
                for(int i = y; i <=z; i++){
                p2steps++;
                }
            }
        

        if(p1steps < p2steps) return 1;
        if(p2steps < p1steps) return 2;
        if(p1steps == p2steps) return 0;

        return 0;
    }
};
int main() {
    Solution s;
    cout << s.findClosest(1, 2, 3) << endl;
    return 0;
}