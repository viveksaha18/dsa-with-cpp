#include<bits/stdc++.h>
using namespace std; 



/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
 

Example 1:

Input
["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
[[], [100], [80], [60], [70], [60], [75], [85]]
Output
[null, 1, 1, 1, 2, 1, 4, 6]

Explanation
StockSpanner stockSpanner = new StockSpanner();
stockSpanner.next(100); // return 1
stockSpanner.next(80);  // return 1
stockSpanner.next(60);  // return 1
stockSpanner.next(70);  // return 2
stockSpanner.next(60);  // return 1
stockSpanner.next(75);  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
stockSpanner.next(85);  // return 6
 
*/

// Time Complexity : O(n2) in worst case
// Space Complexity : O(n) for storing the prices

class StockSappner {
vector<int> ans;
public:
    StockSappner() {

    }

    int nextprice(int price) {
        ans.push_back(price);
        int span = 1;
        for(int i = ans.size() - 2; i >= 0; i--) {
            if(ans[i] <= price) {
                span++;
            }
            else break;
        }
        return span;
    }
};



/*
using the previous greater element approach 
*/

class StockSpannerOptimized {
    stack<pair<int, int>> st;
    int idx = 0;
    public:
    StockSpannerOptimized() {

    }
    int next(int price) {
        int curIdx = idx++;
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int prevGreaterIdx = st.empty() ? -1 : st.top().second;
        int span = curIdx - prevGreaterIdx;
        st.push({price, curIdx});
        return span; 
    }
};
int main() {
    StockSappner s1;
    int price1 = s1.nextprice(100);
    int price2 = s1.nextprice(80);
    int price3 = s1.nextprice(60);
    int price4 = s1.nextprice(70);
    int price5 = s1.nextprice(60);
    int price6 = s1.nextprice(75);
    int price7 = s1.nextprice(85);
    cout << price1 << " " << price2 << " " << price3 << " " << price4 << " " << price5 << " " << price6 << " " << price7 << endl;

    StockSpannerOptimized s2;
    int optPrice1 = s2.next(100);
    int optPrice2 = s2.next(80);
    int optPrice3 = s2.next(60);
    int optPrice4 = s2.next(70);
    int optPrice5 = s2.next(60);
    int optPrice6 = s2.next(75);
    int optPrice7 = s2.next(85);
    cout << optPrice1 << " " << optPrice2 << " " << optPrice3 << " " << optPrice4 << " " << optPrice5 << " " << optPrice6 << " " << optPrice7 << endl;
    return 0;
}