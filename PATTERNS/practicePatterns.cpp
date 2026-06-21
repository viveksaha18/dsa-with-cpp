#include<bits/stdc++.h>
using namespace std;
void squarePattern(int n) {
    /*
        * * * *
        * * * *
        * * * * 
        * * * *
    */

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}
void rightAngleTrianglePattern(int n) {
    cout << "Right Angled Triangle " << endl;
    /*
        *
        **
        ***
        ****
    */
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void invertedRightAngleTrianglePattern(int n) {
    cout <<"Inverted Right Angle Triangle Pattern" << endl;
    /*
        * * * *
        * * *
        * *
        * 
    */
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

void numberTrianglePattern(int n) {
    cout << "Number Triangle Pattern" << endl;
    /*
        1
        1 2 
        1 2 3 
        1 2 3 4
    */
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << endl;
    }
}


void sameNumberTrianglePattern(int n) {
    cout << "Same Number Triangle Pattern " << endl;
    /*
        1 
        2 2 
        3 3 3 
        4 4 4 4
    */
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << i << " ";
        }
        cout << endl;
    }
}


void pyramidPattern(int n) {
    cout << "Pyramid Pattern" << endl;
    // Step 1: Print Space 
    // Step 2: Print Star
    for(int i = 0; i < n; i++) {
        // Print Space
        for(int j = 0; j < (n-i-1); j++) cout << " ";
        // Print Stars
        for(int j = 0; j < (2*i+1); j++) cout << "*";
        cout << endl;
    }
}

void invertedPyramidPattern(int n) {
    cout << "Inverted Pyramid Pattern" << endl;
    for(int i = n-1; i >= 0; i--) {
         for(int j = 0; j < (n-i-1); j++) cout << " ";
        // Print Stars
        for(int j = 0; j < (2*i+1); j++) cout << "*";
        cout << endl;
    }
}
int main() {
    int n = 4;
    squarePattern(n);
    rightAngleTrianglePattern(n);
    invertedRightAngleTrianglePattern(n);
    numberTrianglePattern(n);
    sameNumberTrianglePattern(n);
    pyramidPattern(n);
    invertedPyramidPattern(n);
    return 0;
}