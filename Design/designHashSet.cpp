#include <bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    unordered_set<int> st;

public:
    MyHashSet() {
        // constructor
    }
    
    void add(int key) {
        st.insert(key);
    }
    
    void remove(int key) {
        st.erase(key);
    }
    
    bool contains(int key) {
        return st.find(key) != st.end();
    }
};

int main() {
    MyHashSet obj;
    
    obj.add(10);
    obj.add(20);
    
    cout << obj.contains(10) << endl; // 1 (true)
    cout << obj.contains(30) << endl; // 0 (false)
    
    obj.remove(10);
    cout << obj.contains(10) << endl; // 0 (false)

    return 0;
}
