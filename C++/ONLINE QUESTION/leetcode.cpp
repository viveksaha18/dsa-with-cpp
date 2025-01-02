#include<bits/stdc++.h>
using namespace std;

// checks whether the string is plaindrome
bool isPalindrome(string s) {
      string cleaned;
        // uses another  string which takes non-alphanumeric chars and lowercase chars 
        for(char c:s){
            if(isalnum(c)) // checks if the string is alphanumeric 
            {
                cleaned+=tolower(c);//  convert uppercase to lowercase and added in the cleaned string 
            }
        }
        // now check if the reverse of cleaned string is equal to cleaned string 
        string rev=cleaned;
        reverse(rev.begin(),rev.end());
        if(cleaned==rev){
            return true;
        }
        else{
            return false;
        }
    }
// most frequent number 
int freqnum(int n, int k ,int arr[]){
    // we use sliding window method 
    sort(arr,arr+n);
    int left=0;
    int ans=0;
    int current=0;
    int target;
    for(int right=0;right<n;right++){
        target=arr[right];
        current+=target;
        while(((right-left+1)*target)-current> k){    // if the operation becomes greater than the given k operation so we have remove
                                                     //element from the window from the left and increament left 
            current-=arr[left];
            left++;
        }
        ans=max(ans,right-left+1); // right-left+1 is the size of the window(subarray)
    }
    return ans;
}   
int removeDuplicates(vector<int>& nums, int n) {
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        nums.clear();
        for(const int& n : s){
            nums.push_back(n);
        }
        return s.size();
    }

// checks if the array is sorted and rotated 
 bool check(vector<int>& nums, int n) {
        int count=0;
        if (nums[0] < nums[n - 1]) {
            count++;   // breakpoints
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                count++; // breakpoints
            }
            if(count>1){
                return false;
            }
        }
        return true;
 }

 void rotate(vector<int>& nums,int n, int k) {
        
           k = k % nums.size();

        // Step 1: Reverse the entire array
        std::reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        std::reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining n-k elements
        std::reverse(nums.begin() + k, nums.end());
}

int  subarraySum(vector<int>& arr, int k) {
        int sum=0;
        int cnt=0;
        for(int i=0;i<arr.size();i++){
            sum=0;
            for(int j=i;j<arr.size();j++){
                sum+=arr[j];
                if(sum ==k){
                    cnt++;
                }
            }
        }
    return cnt;
}
int main(){
/*// 1->
    int plaindrome=isPalindrome("A man, a plan, a canal: Panama");
    cout<<plaindrome<<endl; // prints 1 if the statement in the fucntion is true 


// 2->
    int n;
    cout<<"Enter the size of the array : "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];  // Input in the array 

// 3->    
    int k;
    cout<<"Enter the number of operations : "<<endl;
    cin>>k;
   int freq = freqnum(n,k,arr);
   cout<<"The most frequent : "<<freq<<endl;

// 4-> Check the array is sorted and rotated
    int n;
    cin>>n;   // size of the array
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin>>nums[i];   // Input in the array
    int result=check(nums,n);
//5-> Remove duplicates element in array and return the size 
    int n;
    cin>>n;   // size of the array
    vector<int> nums(n);
    for(int i=0;i<n;i++)  cin>>nums[i];   // Input in the array
    int result=removeDuplicates(nums,n);
//6-> Rotating an array by k places
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    int k;
    cin>>k;
    rotate(nums,n,k);
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";
    return 0;
// 7-> Moves zero's to end
    

*/
// 8-> Subarray equals to k 
    int n;
    cout<<"Enter the size of the array :"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cout<<"Enter the target value : "<<endl;
    cin>>k;
    int ctch =subarraySum(arr,k);
    cout<<"the catch value "<<ctch;
    return 0;
}