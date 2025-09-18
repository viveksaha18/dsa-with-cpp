#include <bits/stdc++.h>
using namespace std;

// Problem Link : "https://leetcode.com/problems/design-task-manager/"

class TaskManager {
public:
    typedef pair<int, int> P; // {priority, taskId}
    priority_queue<P> maxHeap;
    unordered_map<int, int> taskPriorityMap; // taskId -> priority
    unordered_map<int, int> taskOwnerMap;    // taskId -> userId

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        maxHeap.push(make_pair(priority, taskId));
        taskPriorityMap[taskId] = priority;
        taskOwnerMap[taskId] = userId;
    }

    void edit(int taskId, int newPriority) {
        maxHeap.push(make_pair(newPriority, taskId));
        taskPriorityMap[taskId] = newPriority;
    }

    void rmv(int taskId) {
        taskPriorityMap[taskId] = -1; // lazy deletion
    }

    int execTop() {
        while (!maxHeap.empty()) {
            pair<int, int> topTask = maxHeap.top();
            maxHeap.pop();
            int prio = topTask.first;
            int taskId = topTask.second;

            if (prio == taskPriorityMap[taskId]) {
                taskPriorityMap[taskId] = -1; // mark as executed
                return taskOwnerMap[taskId];
            }
        }
        return -1; // no tasks left
    }
};

int main() {
    // Sample tasks: {userId, taskId, priority}
    vector<vector<int>> tasks = {
        {1, 101, 5},
        {2, 102, 10},
        {3, 103, 7}
    };

    TaskManager obj(tasks);

    obj.add(4, 104, 15);   // Add taskId 104 for user 4 with priority 15
    obj.edit(102, 20);     // Update priority of taskId 102
    obj.rmv(101);          // Remove taskId 101

    int topUser = obj.execTop();  // Execute top priority task
    cout << "Top task executed by user: " << topUser << endl;

    topUser = obj.execTop();      // Next top task
    cout << "Next task executed by user: " << topUser << endl;

    topUser = obj.execTop();      // Next top task
    cout << "Next task executed by user: " << topUser << endl;

    return 0;
}
