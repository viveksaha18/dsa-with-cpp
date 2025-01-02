#include <bits/stdc++.h>
using namespace std;
// Reverse an array

void reversearr(){
    int n;
    n=5;
    int a[5]={4,3,2,1,5};
    for(int i=0;i<n/2;i++){
        int temp=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=temp;

    }

    // array after reverse
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}

// approach for recursion
 void rev_rec(int i, int arr[], int n){
    if(i>=n/2){
        return ;
    }
    swap(arr[i],arr[n-i-1]);
    rev_rec(i+1,arr,n);
}

// Hashing 
int hashing(int n, int arr[]){
    int P;
    cout<<"Enter the P : "<<endl;
    cin>>P;
    int hash[P+1]={0};

        // Count frequencies of elements in arr that are between 1 and P.
        for (int i = 0; i < n; i++) {
            if (arr[i] >= 1 && arr[i] <= P) {
                hash[arr[i]]++;
            }
        }

        // Return the hash array (excluding the 0th index since we only care about elements from 1 to P).
        
        for(int i=1;i<=P;i++) cout<<hash[i];
}

// Performing selection sort
int select(int i, int arr[], int n){           // This function contains the inne loop 
    int min=i;
    for(int j=i+1;j<=n-1;j++){
        if(arr[j]<arr[min]){                  // Modifiy the minimum which we assume to be 
            min=j;
        }
    }
    return min;
}
void selectionsort(int n, int arr[]){           // This function contains the outer loop 
    for(int i=0;i<=n-2;i++){
        int min=select(i,arr,n);
        swap(arr[min],arr[i]);                  // just swaping between minimum element and the ith index 
    }
    cout<<"The array after sorting : "<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
} 
// Return the sorted array using bubble sort
int*  bubblesort(int n, int arr[]){
    
    for (int  i=n-1; i>=1;i--)
    {
        for (int j=0;j<=i-1;j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return arr;
}
// Return the sorted array using insertion sort
int* insertionsort(int arr[], int n){
    int j;
    for(int i=0;i<=n-1;i++){
        j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
    return arr;
}
// Return the sorted array using merges sort
// Function declaration 
void msort(vector<int> &arr, int low, int high);
void mrg(vector<int> &arr, int low, int mid, int high);

// Merge sort based on the concept of multiple recursion 
void msort(vector<int> &arr, int low, int high) {
    if (low >= high) return; // Base case
    int mid = (low + high) / 2;
    msort(arr, low, mid);       // Sort left half
    msort(arr, mid + 1, high);  // Sort right half
    mrg(arr, low, mid, high);   // Merge sorted halves
}

// Here the merge happens 
void mrg(vector<int> &arr, int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp; // Temporary array for merging 

    // Merge the two subarrays into temp
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Add remaining elements from the left subarray
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Add remaining elements from the right subarray
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy the merged elements back to the original array
    for (int i = low; i <=high; i++) {
        arr[i]=temp[i-low];
    }
}
// Return the sorted array using quick sort 
int partition(vector<int> &arr , int low ,int high )
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot && i<=high)
        {
            i++;
        }
        while(arr[j]>pivot && j>=low)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);   // gives pivot to correct position
    return j;  // return the partition 
}
void  qs(vector<int> &arr , int low , int high )
{
    if(low<high)
    {
        int pindex=partition(arr,low,high);
        qs(arr,low,pindex-1);// Recursively sort left portion
        qs(arr,pindex+1,high); //Recursively sort right portion
    }
}

// Finding the greatest element in the array       
// Time complexity should be O(n) and space complexity should be O(1) 
// solution 
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
// Finding the second largest element in the array with time complexity O(n) and space complexity O(1)
int slargest(int arr[], int n){
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
int main()
{ 
    // reverse array problems 

   /* reversearr();
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    rev_rec(0,arr,n);
    for(int i=0;i<n;i++) cout<<arr[i];


// for hashing 
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++) cin>>arr[i];
    hashing(n,arr); 


// Sorting 


   //1->Selection Sort
   int n;
   cout<<"Enter the size of the array : "<<endl;
   cin>>n;
   int arr[n];
   cout<<"Enter the elements in the array : "<<endl;
   for(int i=0;i<n;i++) cin>>arr[i];
   selectionsort(n,arr);
   //2->Bubble Sort 
   int n;
   cout<<"Enter the size of the array : "<<endl;
   cin>>n;
   int* arr=new int[n];
   cout<<"Enter the elements in the array : "<<endl;
   for(int i=0;i<n;i++) cin>>arr[i];
   bubblesort(n,arr); 
   for(int i=0;i<n;i++) cout<<arr[i]<<" ";
   //3->Insertion Sort
   int n;
   cout<<"Enter the size of the array : "<<endl;
   cin>>n;
   int* arr=new int[n];
   cout<<"Enter the elements in the array : "<<endl;
   for(int i=0;i<n;i++) cin>>arr[i];
   insertionsort(arr,n); 
   for(int i=0;i<n;i++) cout<<arr[i]<<" ";
   //4->Merge Sort
   int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n); // Initialize the vector with size n
    cout << "Enter the elements in the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    msort(arr, 0, n - 1); // Call the msort function to sort the array

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    //5->Quick Sort
    int n;
    cout<<"Enter the size of the array :"<<endl;
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements in the array : "<<endl;
    for(int i=0;i<n;i++) cin>>arr[i];  //Input in the array 
    int low=0;
    int high=n-1;
    qs(arr,low,high);
    // Array after quick sort 
    for (int  i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }

*/
//Arrays 


   // 1.Finding the largest element in the array 
   int n;
   cout<<"Enter the size of the array :"<<endl;
   cin>>n;
   int*arr = new int[n];
   cout<<"Enter the elements in the array : "<<endl;
   for(int i=0;i<n;i++) cin>>arr[i];
   largestnum(arr,n);
   //2.Finding the second largest element in the array
   int n;
   cout<<"Enter the size of the array :"<<endl;
   cin>>n;
   int*arr = new int[n];
   cout<<"Enter the elements in the array : "<<endl;
   for(int i=0;i<n;i++) cin>>arr[i];
   slargest(arr,n);
   

   return 0; 
}