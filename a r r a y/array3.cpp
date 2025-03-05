#include<bits/stdc++.h>
using namespace std;

// Question 1 Variation 1 

/*
Pascal triangle looks like - 
                1                           
            1       1
        1       2       1
    1       3       3       1
1       4       6       4       1

// Finding any number = r-1 Combination  c-1  where r is the number of rows any c is the number of columns 
*/
void pascal_variation1(int row, int col){

    // Formula --- >>  r-1 C c-1  = nCr  = n! / r!*(n-r)! combination formula 

    row = row - 1;
    col = col - 1;   // to compute the formula r-1 C c-1
    
    long long  ans = 1;

// Here calculating nCr 
    for(int i = 0; i < col; i++){
        ans = ans * (row - i);
        ans = ans / (i+1);
    }
    cout<<"The element found is : "<<ans<<endl;

}

// Variation - 2  -- > Give the row number return the row 
void pascal_variation2( int   n ){ // n is the row 

   


    vector<int> ansRow;
    // Storing the entire row 
    long long ans = 1;
    ansRow.push_back(1);

    for(int col = 1; col < n; col++){
        ans = ans * (n - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
// Printing entire row
for(auto it : ansRow){
    cout<<it<<" ";
}
}

// Variation 3 
// Printing the entire triangle
vector<int> pascal_variation3(int i ){
        vector<int> ansRow;
    // Storing the entire row 
    long long ans = 1;
    ansRow.push_back(1);

    for(int col = 1; col < i; col++){
        ans = ans * (i - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
return ansRow;
}


// Question 2 
// Brute Force Approach 
void majorityElement_Brute(vector<int> &arr){
    int n = arr.size();
    vector<int> ans; // for storing the ans 
    set<int> s; // not to take repeated ones 
    int atmax = n / 3;

    for(int i = 0; i < n; i++){
        int cnt = 0; 
        for(int j = 0; j < n; j++){
            if(arr[i] == arr[j]){
                cnt++;
            }
        }
        if(cnt > atmax){
            s.insert(arr[i]);
        }
    }
    for(auto it : s){
        ans.push_back(it);
    }

    // printing the values greater than n / 3
    for(auto it : ans){
        cout<<it<<" ";
    }
}

// Better Approach 
// Using of map data structure
void majorityElement_Better(vector<int> &arr){
    vector<int> ans;  // for storing the answer
    int n = arr.size();  
    int atmax = n / 3;

    unordered_map<int,int> mpp;   // for storing the occurence 
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second > atmax){
            ans.push_back(it.first);
        }
    }

    for(auto it : ans){
        cout<<it<<" ";
    }
}

// Optimal Approach 
/*
Intiuition : We use moore's voting algorithm (extended version ) 
*/
void majorityElement_Optimal(vector<int> &arr){
    int n = arr.size();
    int ele1 = INT_MIN , ele2 = INT_MIN;
    int cnt1 = 0 , cnt2 = 0; 
    vector<int> ans; 

    for(int i = 0; i <n; i++){
        if(cnt1 == 0 && arr[i] != ele2){
            cnt1 = 1;
            ele1 = arr[i];
        }
        else if(cnt2 == 0 && arr[i] != ele1){
            cnt2 = 1;
            ele2 = arr[i];
        }
        else if(arr[i] == ele1){
            cnt1++;
        }
        else if(arr[i] == ele2){
            cnt2++;
        }
        else {
            cnt1-- , cnt2--;
        }
    }
    cnt1=0 , cnt2=0;
    for(int i = 0; i < n; i++){
        if(arr[i] == ele1) cnt1++;
        if(arr[i] == ele2) cnt2++;
    }

    if(cnt1 > n/3) ans.push_back(ele1);
    if(cnt2 > n/3) ans.push_back(ele2);

    sort(ans.begin(),ans.end());
    for(auto it : ans){
        cout<<it<<" ";
    }
}

// Question 3
/*
Brute Force Approach 
Intituition : Generate all the triplets & sort them & store in a set 

Time Complexity : O(n3) and Space Complexity : 2 * O(no of triplets)
*/
void threeSum_Brute(vector<int> &arr,int n){
    set<vector<int>> st; // for storing the unique triplets 

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i] , arr[j] , arr[k]};
                    sort(temp.begin() , temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin() , st.end() );
    
    for(auto it : ans){
        cout<<"[";
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<"]";
    }

cout<<endl; 
}

// Better Solution 
/*
Intituition : Optimize the brute like somewhere time complexity be O(n) we know arr[i] + arr[j] + arr[k] = 0 then it is our
one of the triplets like if we do arr[k] = -(arr[i] + arr[j]) if we found that third element which is arr[k] so we are 
able to found our triplet and we don't then add to a container .

Time Complexity : O(n2) and Space Complexity : 2 * O(no of triplets) 
*/
void threeSum_Better(vector<int> &arr, int n){
    set<vector<int>> st; // for storing unique triplets 
    for(int i = 0; i < n; i++){
        set<int> hash;
        for(int j = i + 1; j < n; j++){
            int third = -(arr[i] + arr[j]); 
            if(hash.find(third) != hash.end()){
                vector<int> temp = {arr[i] , arr[j] , third};
                sort(temp.begin() , temp.end());
                st.insert(temp);
            }
            hash.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin() , st.end());
    // Output 
    for(auto it : ans ){
        cout<<"[";
        for(auto i : it ){
            cout<<i<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
}

/*
Optimal Approach 
Intituition : First we sort the entire  array and then use a two pointer approach place i at first position j at next to i and k at last 
position .

Time Complexity : O(n2) and Space Complexity : O(n)
*/
void threeSum_Optimal(vector<int> &arr, int n){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue; // avoiding the same element for i 
        int j = i + 1;
        int k = n - 1;
        while( j < k ){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                ans.push_back({arr[i] , arr[j] , arr[k]});
                j++;
                k--;
            
                while( j < k && arr[j] == arr[j - 1]) j++; // for avoiding duplicates 
                while( j < k && arr[k] == arr[ k + 1]) k--; // for avoiding duplicates 
            }
        }
    }
    // Output 
    for(auto it : ans){
        cout<<"[";
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<"]";
    }
}


/*
Question 4 
Four Sum 
Brute Force Approach 
Time Complexity : O(n^4) and Space Complexiy : 2 * O(no of quadra triplets)
*/
void fourSum_Brute(vector<int> &arr,int n, int target){
    set<vector<int>> st;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                for(int l = k + 1; l < n; l++){
                    long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if(sum == target){
                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());

    // Output 
    for(auto it : ans){
        cout<<"[";
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
}

// Better Solution 
void fourSum_Better(vector<int> &arr,int n,int target){
    set<vector<int>> st;
     
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            set<int> hashSet;
            for(int k = j + 1; k < n; k++){
                int  fourth = target -(arr[i] + arr[j] + arr[k]);
                if(hashSet.find(fourth) != hashSet.end()){
                    vector<int> temp = {arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashSet.insert(arr[k]);
            }
        }
    }

    // for storing answer 
    vector<vector<int>> ans(st.begin(),st.end());

    // Output
    for(auto it : ans){
        cout<<"[";
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<"]";
    }
cout<<endl;
}

// Optimal Approach - Same as 3sum 
void fourSum_Optimal(vector<int> &arr,int n,int target){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < n; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(int j = i + 1; j < n; j++){
            if( j > 1 && arr[j] == arr[j-1]) continue;
            int left = j + 1 , right = n - 1;
            while(left < right){
                long long sum = arr[i] + arr[j] + arr[left] + arr[right];
                if(sum < target){
                    left++;
                }
                else if(sum > target){
                    right--;
                }
                else{
                    ans.push_back({arr[i] , arr[j] , arr[left] , arr[right]});
                    left++;
                    right--;
                    while( left <= right && arr[left] == arr[left-1] ) continue;
                    while( left <= right && arr[right] == arr[right+1]) continue;
                }
            }
        }
    }
    // Output
     for(auto it : ans){
        cout<<"[";
        for(auto i : it){
            cout<<i<<" ";
        }
        cout<<"]";
    }
}


/*
Question 5 
Brute Force Approach : Generate all the subarray which sum == 0 & pick the longest one 
Time Complexity : O(n^2) and Space Complexity : O(1)
*/
void largestsubarayzeroSum_Brute(vector<int> &arr,int n){
    int length = INT_MIN;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = i; j < n; j++){
            sum+=arr[j];
            if(sum == 0){
                length = max(length , j-i+1);
            }
        }      
    }
    if(length == INT_MIN){
        cout<<0;
    }
    cout<<"The largest subarray with sum zero is : "<<length;
    cout<<endl;
}
/*
Better Solution : 
Prefix Concept : Using Hashing 

*/
void largestsubarayzeroSum_Better(vector<int> &arr,int n){
    unordered_map<int,int> prefixSum;
    int sum = 0 , maxi = 0; 
    for(int i = 0; i < n; i++){
        sum+=arr[i];
        if(sum == 0){
            maxi = i + 1;
        }
        else if(prefixSum.find(sum) !=prefixSum.end()){
            maxi = max(maxi,i-prefixSum[sum]);
        }
        else{
            prefixSum[sum] = i;
        }
    }
    if(maxi == 0) cout<<"zero"<<endl;
    cout<<"The length of largest sum "<<maxi<<endl;
}



// Question 6
/*
Brute Force Approach : Generates all the subarray's which meets the target and return the number of subarrays.
*/
void xor_Brute(vector<int>& arr,int n,int b){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int Xxor = 0;
            for(int k = i; k <= j; k++){
                Xxor= Xxor ^ arr[k];
            }
            if(Xxor == b) cnt++;
        }
    }
    cout<<cnt;
}

// Better Solution : Time complexity : O(n2) and Space Complexity : O(1)
void xor_BetterSolution(vector<int>& arr,int n,int b){
    int cnt = 0; 
    for(int i = 0; i < n; i++){
        int Xxor = 0;
        for(int j = i; j < n; j++){
            Xxor = Xxor ^ arr[j];
            if(Xxor == b) cnt++;
        }
    }
    cout<<cnt;
}

/* Optimal Solution : In this approach we use the concept of prefix xor . Lets assume that the prefix xor of a subarray ending 
at index i is 'xr' . In that subarray we will search for another subarray ending at index i , whose xor is equal to the target value
. Here we need to observe that if there exist another subarray ending at index i with xor k , then the prefix xor of the rest of the subarray
will be the target value.

Time complexity : O(n2) 
Space Complexity : O(n)

*/
void xor_OptimalSolution(vector<int>& arr,int n,int b){
    unordered_map<int,int> mpp;
    int xr = 0; 
    int cnt = 0;
    mpp[xr]++;
    for(int i = 0; i < n; i++){
        xr^=arr[i];
        int x=xr^b;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    cout<<cnt;
}
int main(){
    /*
    //1.Pascal's Triangle 
    These question has three variation 
    ->  Variation 1 -
    Given the row number and column number return the element at that row and column position 
    
    
   
   int row = 5 , col = 3;
   pascal_variation1(row,col);
    int n = row + 1;
   pascal_variation2(n);

   // variation 3 
   // Printing the entire triangle
   
   int numofRows = 6;
   vector<vector<int>> ans; // for storing the entire traingle
   for(int i = 1; i <= n; i++){
    vector<int> temp = pascal_variation3(i);
    ans.push_back(temp);
    // Printing the entire triangle
    for(auto it : temp){
        cout<<it<<" ";
    }
    cout<<endl;
   }
   
   
   // 2. Majority Element || 
   // Given an integer array  find all elements appear more than [n/3] times 
   vector<int> arr = {3,1,3};
   majorityElement_Brute(arr);

   // Better Approach 
   majorityElement_Better(arr);
   
   // Optimal Approach 
    majorityElement_Optimal(arr); 
*/

    // 3. Three Sum 
    /*
    Return the unique triplets whose sum = 0 remember [i != j != k] store them in sorted order and nor duplicate triplet 
    
    vector<int> arr = {-1,0,1,2,-1,4};
    int n = arr.size();
    threeSum_Brute(arr,n);

    // Better soln 
    threeSum_Better(arr,n);

    // Optimal soln 
    threeSum_Optimal(arr,n);



// 4. Four Sum 
// Similar to three sum but there is a target  and Output is [-3 -1 2 5 ][-3 0 2 4 ]
vector<int> arr = {-3,-1,0,2,4,5};
int n = arr.size();
int target = 3;
fourSum_Brute(arr,n,target);

// Better Solution 
fourSum_Better(arr,n,target);

//Optimal one
fourSum_Optimal(arr,n,target);


// 5.Largest Subarray with 0 sum 
vector<int> arr = {15,-2,2,-8,1,7,10,23};  // Output 5 -2 2 -8 1 7 
int n = arr.size();
largestsubarayzeroSum_Brute(arr,n);

// Better Solution 
largestsubarayzeroSum_Better(arr,n);
*/

// 6.Subarray with given xor 
/*
Given an array of interger A and an integer B . Find the total number of subarray bitwise xor of all elements equals to B
*/
vector<int> arr = {4,2,2,6,4};
int n = arr.size();
int b = 6;
xor_Brute(arr,n,b);

// Better Solution 
xor_BetterSolution(arr,n,b);

// Optimal Solution 
xor_OptimalSolution(arr,n,b);


    return 0;
}