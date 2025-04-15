#include <bits/stdc++.h>
using namespace std;

class Queue {
    int* arr;
    int capacity; // max size
    int currSize;
    int start, end;

public:
    Queue(int size) {
        arr = new int[size];
        capacity = size;
        currSize = 0;
        start = -1;
        end = -1;
    }

    void push(int val) {
        if (currSize == capacity) {
            cout << "Queue is Full" << endl;
            return;
        }

        if (currSize == 0) {
            start = end = 0;
        } else {
            end = (end + 1) % capacity;
        }
        arr[end] = val;
        currSize++;
    }

    int pop() {
        if (currSize == 0) {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        int ele = arr[start];
        if (currSize == 1) {
            start = end = -1;
        } else {
            start = (start + 1) % capacity;
        }
        currSize--;
        return ele;
    }

    int topele() {
        if (currSize == 0) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[start];
    }

    int getSize() {
        return currSize;
    }
};

int main() {
    Queue obj(4);  // max size = 4

    obj.push(3);
    obj.push(2);
    obj.push(4);

    cout << "Front: " << obj.topele() << endl;

    cout << obj.pop() << endl;
    cout << obj.pop() << endl;

    obj.push(2);
    obj.push(3);

    cout << obj.pop() << endl;
    cout << obj.pop() << endl;
    cout << obj.pop() << endl;  // Should print Queue is Empty

    return 0;
}
