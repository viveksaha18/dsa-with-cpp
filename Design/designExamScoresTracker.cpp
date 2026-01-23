#include<bits/stdc++.h>
using namespace std;
class ExamTracker {
public:
// map<time, totalScore>
// totalScore = the score till the endTime and the score before the starttime
map<int, long long> prefix;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        long long lastScore = 0;
        if(!prefix.empty()) {
            lastScore = prefix.rbegin()->second;
        }
        prefix[time] = lastScore+score;
    }
    
    long long totalScore(int startTime, int endTime) {
        if(prefix.empty()) return 0;
        auto itEnd = prefix.upper_bound(endTime);
        long long sumEnd = (itEnd == prefix.begin()) ? 0 : prev(itEnd)->second;
        auto itStart = prefix.lower_bound(startTime);
        long long sumStart = (itStart == prefix.begin()) ? 0 : prev(itStart)->second;
        return sumEnd - sumStart;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
int main() {
    ExamTracker* obj = new ExamTracker();
    int startTime = 10, endTime = 20;
    int time = 15, score = 50;
    obj->record(time,score);
    long long param_2 = obj->totalScore(startTime,endTime);
    cout << param_2;
    return 0;
}