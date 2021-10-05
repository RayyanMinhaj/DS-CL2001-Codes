/*
* * * * * * * * * * *
*	Rayyan Minhaj	* 
*	 20K-0143	    *
*	  BCS-3C		*
*  02-October-2021  *
* * * * * * * * * * *



You are given a one-dimensional array of integers of size n. You need to find a sub-array of the given array such that the sum of the element of sub
array is maximum. The problem is to find an efficient method that find any such instance of sub array quickly.   

Input  

The first line of input is an integer n, the next line provided space separated n integers for the array.  

Output  

The output produces the sub array elements (space separated) in the first line and the sum(maximum sum) in the second line.



INPUT:
10
11 23 45 67 -19 101 -25 3 4 -324

OUTPUT:
11 23 45 67 -19 101 
228


*/


#include <iostream>

using namespace std;


template<class T>
void max_subarray(T arr, int n){
	int max=-121212121212;
	int sum=0;
	int count=0;
	int first=0;
	int last=0;
	int s=0;
	
	//11 23 45 67 -19 101 -25 3 4 -324
	
	for(int i=0;i<n;i++){
		sum=sum+arr[i];
		
		if(max<sum){
			max=sum;
			first=s;
			last=i;
				
		}
		
		if(sum<0){
			sum=0;
			s=i+1;
		}
		

	}
	
	
	for(int i=first;i<=last;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<max;
	
}




int main() {
	// use standard input and output (no file i/o required)
	// TODO: Your solution here
	
int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	max_subarray(arr,n);
	

	return 0; // always return 0 from here
}

