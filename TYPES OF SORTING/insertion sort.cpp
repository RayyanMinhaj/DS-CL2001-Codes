#include<iostream>
using namespace std;

int main(){
	int arr[10]={1,2,7,14,3,9,11,10,0,5};
	int temp=0;
	
	for(int i=0;i<10;i++){
		temp=arr[i];
		
		while(i!=0){
			if(arr[i]<arr[i-1]){
				swap(arr[i],arr[i-1]);
				i--;
				
				for(int k=0;k<10;k++){
					cout<<arr[k]<<" ";
				}
				cout<<endl<<endl;
			}
			else{
				break;
			}
		}
		
	}
	
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	
}
