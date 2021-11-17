#include<iostream>
using namespace std;

int main(){
	string arr="ASORTINGEXAMPLE";
	int temp=0;
	
	for(int i=0;i<15;i++){
		//temp=arr[i];
		
		while(i!=0){
			if(arr[i]<arr[i-1]){
				swap(arr[i],arr[i-1]);
				i--;
			
			}
			else{
				break;
			}
		}
		
	}
	
	for(int i=0;i<15;i++){
		cout<<arr[i]<<" ";
	}
	
}
