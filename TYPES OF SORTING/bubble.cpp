#include<iostream>
using namespace std;

int main(){
	int arr[10]={1,2,7,14,3,9,11,10,0,5};
	
	int temp=0;
	cout<<"~~~BUBBLE SORT~~~"<<endl<<endl;

	
	for(int i=0;i<10-1;i++){
		for(int j=0;j<10-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
				for(int k=0;k<10;k++){
					cout<<arr[k]<<" ";
				}
				cout<<endl<<endl;
			}
			
			
			
			
		}
	}
	
	
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	
}
