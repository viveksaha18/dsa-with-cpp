#include<bits/stdc++.h>
using namespace std;


// for question number 4 declaring  a global vector 
vector<vector<int> > ans;   


// Question 1
// Brute Force Approach 
//Time complexity : O(n log n) and Space complexity : O(1)
void* largestnum1(int  arr[],int n){
    sort(arr,arr+1);
    cout<<arr[n-1];
}
// Optimal Approach
//Time complexity : O(n) and Space complexity O(1) 
void* largestnum(int arr[], int n){
    int largest=arr[0];
    for (int  i = 0; i < n; i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    cout<<"The largest element of the array is : "<<largest<<endl;
}


// Question 2 
// Brute Force Approach works when there is no duplicate element present in the array 
// Time complexity : O(n log n ) and Space complexity : O(1)
int slargest(int arr[], int n){
    sort(arr,arr+1);
    cout<<arr[n-2];
}

// Optimal Approach 
// Time complexity : O(n) and Space Complexity : O(1)
int slargest1(int arr[], int n){
    int largest=arr[0];
    int slargest=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>largest)    
        {
            slargest=largest;
            largest=arr[i];
        }

        else if(arr[i]<largest && arr[i]>slargest){
            slargest=arr[i];
        }
    }
    return slargest;
}

// Question 3  
// Time complexity : O(n) and Space complexity : O(1)
void rotate(vector<int>& nums,int n, int k) {
        
           k = k % nums.size();

        // Step 1: Reverse the entire array
        std::reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        std::reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining n-k elements
        std::reverse(nums.begin() + k, nums.end());
}


// Question 4
// Optimal Approach 
void  perArray(vector<int> &arr , int i){
    if(i==arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int j=i;j<arr.size();j++){
        swap(arr[i],arr[j]);
        perArray(arr,i+1);
        swap(arr[i],arr[j]);
    }
}



// Question 5
bool rotatedSorted(vector<int> &arr , int n){
    int cnt=0;
    if(arr[n-1] > arr[0]){
        cnt=1;
    }
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            cnt+=1;
        }
    }
    
    return cnt <=1;
}


// Question 6
// Brute Force Approach 
// Time complexity : O(n) and Space complexity : O(n)
vector<int> dupElements(vector<int> &arr , int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }
    vector<int> temp;
    for(auto it : s){
        temp.push_back(it);
    }
    return temp;
}


// Optimal Approach  Two pointer approach 
// Time complexity : O(n) and Space complexity : O(1)
int  dupElements1(vector<int> &arr,int n ){
    int j=0;
    for(int i=0;i<arr.size();i++){
        if(arr[j]!=arr[i]){
            arr[++j]=arr[i];
        }
    }
    return ++j;     
    // returning the number of duplicate elements
}


// Question 7 
// Time complexity : O(n) and Space complexity : O(1)
int  movesZeros(vector<int> &arr, int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) {
        cout<<"The array does not contain zeros elements "<<endl;
    }
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}


// Question 8 
// Performing Linear Search Time complexity : O(n) and Space complexity : O(1)
bool linearSearch(vector<int> &arr, int n, int k){
    for(int i=0;i<n;i++){
        if(arr[i]==k){
            return 1;
        }
    }
    return 0;
}


// Question 9
// Using hasing 
// Time complexity : O(n log n ) and Space complexity : O(n)
/*void Union(vector<int> & arr1,vector<int> &arr2 ,int n){
    map<int,int> mpp;
    // for the first array 
    for(int i=0;i<n;i++){
        mpp[arr1[i]]++;
    }
    // for the second array 
    for(int i=0;i<n;i++){
        mpp[arr2[i]]++;
    }
    // Now the unique elements
    for(auto it: mpp){
        cout<<it.first<<" ";
    }
}

// Using set
void Union(vector<int> &arr1, vector<int> &arr2, int n){
    set<int> s;
    for(int i=0;i<n;i++){
        s.insert(arr1[i]);
    }
    for(int i=0;i<n;i++){
        s.insert(arr2[i]);
    }
    for(auto it : s){
        cout<<it<<" ";
    }
}
*/



// Question 10 
//Using hashing     Time complexity : O(n)  Space Complexity O(n)  
// Brute force approach
void missingNumber(vector<int> &arr, int n){
        vector<int> hash(n+1,0);
        int mis=-1;
        for(int i=0;i<n;i++){
            hash[arr[i]]+=1;
        }
        for(int i=0;i<=n;i++){
            if(hash[i]==0){
                mis=i;
                break;
            }
        }
        cout<<"The missing number is : "<<mis<<endl;
    }
// Optimal approach 
// Time complexity : O(n) and Space complexity : O(1)
void missingNumber_optimal(vector<int> & arr, int n){
    int sum=0, sum1=0;
    sum=n*(n+1)/2;
    for(int i=0;i<n;i++){
        sum1+=arr[i];
    }
    cout<<"The missing number is : "<<sum-sum1;
}


// Question 11
// Time complexity : O(n) and Space complexity : O(1)
void maxconOnes(vector<int> &arr){
    int cnt=0;
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            cnt++;
        }
        else{
            cnt=0;
        }
        maxi=max(cnt,maxi);
    }
    cout<<"The largest number of ones present in the array : "<<maxi;
}


// Question 12 
// Brute Force Approach  using hashing  Time complexity : O(1) in best and average case Space complexity : O(n)
void apperOnce(vector<int> &arr){
    unordered_map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]+=1;
    }
    // Looking for the key whose frequecny is one 
    for(auto it : mpp){
        if(it.second ==1 ){
            cout<<it.first<<endl;
        }
    }
}
// Optimal approch 
// Time complexity : O(n) and Space complexity : O(1)
void apperOnceoptimal(vector<int> arr){
    int xor1=0;
    for(int i=0;i<arr.size();i++){
        xor1^=arr[i];
    }
    cout<<xor1<<endl;
}


// Question 13 
// Brute Force Approach  Time complexity : O(n2) and Space complexity : O(1)
void longSubarr(vector<int> &arr,int k){
    int maxlength=0,sum=0;
    for(int i=0;i<arr.size();i++){
        sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            if(sum==k){
                maxlength=max(maxlength,j-i+1);
            }
        }
    }
    cout<<maxlength<<endl;
}
// Optimal Approach 
// Using hashing 
// Here we use reverse mathematics if we found  sum-k then there must be subarray whose sum is equals to k if i not found then put
// the sum into the hashmap and stored the value based on array indexing 
// Time complexity : O(n) and Space complexity : O(n)
void longSubarroptimal(vector<int> & arr, int k){
    map<int,int> mpp;
    int sum=0;
    int maxi=INT_MIN;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        if(sum==k){
            maxi=max(maxi,i+1);
        }
        int rem=sum-k;
        if(mpp.find(rem)!=mpp.end()){
            int len=i-mpp[rem];
            maxi=max(maxi,len);
        }
        if(mpp.find(rem)==mpp.end()){
            mpp[sum]=i;
        }
    }
    cout<<maxi;
}


int main(){
/*
// 1. Largest element in the array 
   int n;
   cout<<"Enter the size of the array :"<<endl;
   cin>>n;
   int*arr = new int[n];
   cout<<"Enter the elements in the array : "<<endl;
   for(int i=0;i<n;i++) cin>>arr[i];
   largestnum(arr,n);

   // for brute approach 
   largestnum1(arr,n);


//2.Second largest element in the array 
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    int slarge=slargest1(arr,n);
    cout<<"The second largest element in the array is :"<<slarge<<endl;
    
    // for brute approach 
    slargest(arr,n);


//3.Rotatation of array by k position 
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int k;
    cin>>k;
    rotate(nums,n,k);
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";


//4. Permutation of an array 
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    perArray(arr,0);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j];
        }
        cout<<" ";
    }


// 5. Check if the array is rotated sorted 
// The condition for an array to be become sorted are
// The array at least have one break point - break point are arr[n-1]>arr[0] and arr[i]>arr[i]
// Example are arr[3,4,5,1,2] In this array there is at least one break point which is 5>1 so it is a rotated sorted array we return true or 1
// One more example [2,1,3,4] there are two break point so we dont considered as this array as rotated sorted array 
// The break point are 4>2 and 2>1
    
    int n;
    cout<<"Enter the size of the array "<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the numbers in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    bool result = rotatedSorted(arr, n);

    // Print 1 for true, -1 for false
    int catchval = result ? 1 : -1;
    cout << catchval << endl;


// 6.Removing duplicates elements from the array  
   
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> result = dupElements(arr,n);
    for(int i=0;i<result.size();i++) cout<<result[i]<<" ";
    cout<<endl;
    
    // for optimal one 
    int ctch=dupElements1(arr,n);
    cout<<"The number of duplicates elements are found : "<<ctch;


// 7.Moves Zeros to End 
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    movesZeros(arr,n);
    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

    
// 8. Linear Search 
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cout<<"Enter the target value you have to find : "<<endl;
    cin>>k;
    int ctch=linearSearch(arr,n,k);
    cout<<ctch<<endl;   // If prints 1 then target value is present 
 

// 9.Find the Union 
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    vector<int> arr1(n);
    vector<int> arr2(n);
    cout<<"Enter the elements in the first array  : "<<endl;
    for(int i=0;i<n;i++) cin>>arr1[i];
    cout<<"Enter the elements in the second array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr2[i];
    Union(arr1,arr2,n);


// 10. Find the missing number 
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    missingNumber(arr,n);

    // for optimal one 
    missingNumber_optimal(arr,n);


//11. Maximum Consecutive ones 
    vector<int> arr={1,0,1,1,0,1};  // output 2
    maxconOnes(arr);


// 12. Find the number that appears once 
    vector<int> arr={4,1,1,2,2}; // output 4
    apperOnce(arr);
    // optimal one 
    apperOnceoptimal(arr);

*/
// 13. Longest sub array with the sum equals to k 
    vector<int> arr={10,5,2,1,7,9};
    int k=15;
    longSubarr(arr,k);
    // for optimal one 
    longSubarroptimal( arr, k);
return 0;

}