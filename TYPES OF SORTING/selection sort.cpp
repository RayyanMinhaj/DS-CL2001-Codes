#include<iostream>
using namespace std;

int main(){
	int arr[10]={1,2,7,14,3,9,11,10,0,5};
	
	cout<<"~~~SELECTION SORT~~~"<<endl<<endl;
	
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(arr[i]<arr[j] && i!=j){
				swap(arr[j],arr[i]);
				
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
