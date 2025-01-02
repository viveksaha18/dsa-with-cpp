#include<bits/stdc++.h>
using namespace std;
void countdigit(int n){
    int sum=0;
    int lastdigit=0;
    while(n>0){
        lastdigit=n%10;
        cout<<" Last digit is "<<lastdigit<<endl;     // It will prints the last digits from the numbers 
        sum++;
        n=n/10;

    }
    cout<<"The total number of digits present are :"<<sum<<endl;  // It will print the number of digits 
}
// count the digits in  n which evenly divides n and return an integer 
int countn(int n){
    int num=n;
    int count=0;
    int lastdigit=0;
    while(n>0){
        lastdigit=n%10;
        if(lastdigit > 0 && num%lastdigit==0){
            count++;
        }
        n=n/10;
    }
    return count;
}
 // one more technique to find the count of digits in a number

int count2(int n){
    int count2=(int)log10(n)+1;
    return count2;
}
// reverse an number 
int rev(int n){
    int last_digit=0;
    int reverse=0;
    while(n>0){
        last_digit=n%10;
        reverse=(reverse*10)+last_digit;
        n/=10;
    }
    return reverse;
}

// if the number exceeds the limit then over flow condition arises 

// checks the number is plaindrome or not 

bool  isPlaindrome(int n){
    int last_digit=0;
        int rev=0;
        int temp=n;
        while(temp>0){
            last_digit=temp%10;
            if(rev>INT_MAX /10 || (rev == INT_MAX/10 && last_digit >7))
                return 0; // over flow condition 
            if(rev < INT_MIN/10 || (rev == INT_MIN /10 && last_digit <-8))
                return 0; // over flow condition 

            rev=(rev*10)+last_digit;
            temp/=10;
        }
        if(rev==n){
            cout<<"The number is plaindrome : "<<n<<endl;
        }
        else{
        cout<<"The number is not plaindrome : "<<n<<endl;
    }
}


 int rev1(int n) {
        int last_digit=0;
        int rev=0;
        while(n!=0){
            last_digit=n%10; // extract last digit basically
            if(rev>INT_MAX /10 || (rev == INT_MAX/10 && last_digit >7))
                return 0; // over flow condition 
            if(rev < INT_MIN/10 || (rev == INT_MIN /10 && last_digit <-8))
                return 0; // over flow condition 
            rev=(rev*10)+last_digit; // using rev variable we just add a number in the variable by multiplying with 10 and then add with last_digit 
            n/=10; // iterationn 
        }
        return rev;
    }

    // checking the number is amstrong or not 
    bool checkArmstrong(int n){
	//Write your code here
	int last_digit=0;
	int dup=n;
	int temp=n;
	int sum=0;
	int count=0;
	while(temp>0){
		count++;
		temp/=10;
	}

        while (n > 0) {
          last_digit = n % 10;
          sum += pow(last_digit, count);
          n /= 10;
        }
			if(sum == dup){
				cout<<"The number is an amstrong number : "<<sum<<endl;
			
			}
			else{
				cout<<"The number you had entered is not a amstrong number "<<sum<<endl;
			}
}

// sum of all the divisor of i
int div(int n)
{
    int divisor =0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i%j==0){
                divisor+=j;
            }
        }
    }
    return divisor;
} // this code exceeds the time limit 

// optimal approach to find the sum of divisor 
int andiv(int n){
    int divisor=0;
    for(int i=1;i<=n;i++){
        divisor+=i*(n/i);
    }
    return divisor;
}

// check the number is prime or not 
// brure force approach 
void  isPrime(int n){
    int factor=0;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            factor++;
        }
    }

    if (factor==2){
        cout<<"The number is prime ."<<endl;
    }
    else{
        cout<<"The number you are entering is not a prime number "<<endl;
    }
}

// optimal approach time complexity square root of n

bool isanPrime(int n)
{
	// Write your code here.
	int fact=0;
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			fact++;
		
        if((n/i)!=i)
			fact++;
		}
	}
	if(fact==2)
	cout<<"Is prime"<<endl;
	else
	cout<<"Not a prime number "<<endl;
}

// hcf or gcd
// brute force approach time complexity in O(min(n1,n2))
int gcd(int n1, int n2){
    int hcf=1;
    for(int i=1;i<=n1;i++){
        if((n1%i==0)&&(n2%i==0)){
            hcf=i;
        }
    }
    return hcf;
}
// optimal solution of gcd 
void angcd(int n1, int n2){
    
    while(n1>0 && n2>0){
        if(n1>n2){
            n1%=n2;
        }
        else{
            n2%=n1;
        }
    }
    if(n1==0){
        cout<<"The hcf of the two numbers is : "<<n2<<endl;
    }
    else{
        cout<<"The hcf of the two numbers is : "<<n1<<endl;
    }
}


// sum of n numbers 
// parameterised way 
void isSum(int i , int sum){
    if(i<1){
        cout<<"The sum of numbers from 1 to n is :" <<sum<<endl;
        return ;
    }
    isSum(i-1,sum+i);
}


// sum of numbers in a functional way we have to return the sum in a function 
int isSum(int n){
    if(n==0){
        return 0;
    }
    return n+isSum(n-1);
}





int main(){
    int n;
    cout<<"Enter the digit"<<endl;
    cin>>n;
    countdigit(n);
    int c=countn(n);
    cout<<"The digit in n which divides n evenly are : "<<c<<endl;
    int anmethod=count2(n);
    cout<<"The digit present in a number is : "<<anmethod<<endl;
    // reverse the numbers 
    int temp=rev(n);
    cout<<"The reverse number of the given number is : "<<temp<<endl;
    int temp1=rev1(n);
    cout<<"Give over flow conditon : "<<rev1<<endl;
    
// checking the number is plaindrome or not
isPlaindrome(n);
// sum of all the divisor of i
int div1=div(n);
cout<<"The divisor of the number is : "<<div1<<endl;


// another method call to find the sum of all the divisor of i 
int div2=andiv(n);
cout<<"The divisorof the number is : "<<div2<<endl;

// checking the number is prime or not 
isPrime(n);
isanPrime(n);

// n1 and n2 are the numbers taken to find the gcd 
int n1,n2;
cout<<"Enter the first digit :"<<endl;
cin>>n1;
cout<<"Enter the second digit :"<<endl;
cin>>n2;
int hcf1=gcd(n1,n2);
cout<<"The hcf of the numbers are :"<<hcf1<<endl;
angcd(n1,n2); 

// sum of numbers using parameterised way 
isSum(n,0);
int catchval=isSum(n);
cout<<"The catch value of the sum of the numbers will be  :"<<catchval<<endl;


    return 0;
}