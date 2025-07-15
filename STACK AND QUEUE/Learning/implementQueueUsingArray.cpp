#include <bits/stdc++.h>
using namespace std;

int size = 4; // Maximum size of the queue
int queueArr[4]; // Array to store queue elements

int front = -1;
int rear = -1;
int currSize = 0;

void pushQueue(int x) {
    if (currSize == size) {
        cout << "Queue is full" << endl;
        return;
    }

    if (currSize == 0) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queueArr[rear] = x;
    currSize++;
}

void popQueue() {
    if (currSize == 0) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << "Popped Element: " << queueArr[front] << endl;

    if (currSize == 1) {
        front = rear = -1; // Reset queue
    } else {
        front = (front + 1) % size;
    }

    currSize--;
}

void topQueue() {
    if (currSize == 0) {
        cout << "Queue is Empty" << endl;
        return;
    }

    cout << "Top Element: " << queueArr[front] << endl;
}

void sizeQueue() {
    cout << "Size of Queue: " << currSize << endl;
}

int main() {
    pushQueue(3);
    pushQueue(2);
    pushQueue(4);
    topQueue();       // Should show 3
    popQueue();       // Remove 3
    popQueue();       // Remove 2
    pushQueue(2);
    pushQueue(3);
    popQueue();       // Remove 4
    popQueue();       // Remove 2
    popQueue();       // Remove 3
    sizeQueue();      // Should show 0
    return 0;
}