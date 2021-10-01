#include<iostream>
using namespace std;

int main(){
	int arr[10]={1,2,7,14,3,9,11,10,0,5};
	
	int n=10;
	cout<<"~~~COMB SORT~~~"<<endl<<endl;
	for(int i=0;i<10;i++){
		n=n/1.3;
		
		for(int j=0;j<10;j++){
			if(arr[j]>arr[j+n] && j+n<=10){
				
				swap(arr[j],arr[j+n]);
				for(int k=0;k<10;k++){
					cout<<arr[k]<<" ";
				}
				cout<<endl<<endl;
			}
			else{
				continue;
			}
		}
	}
	
	
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	
	
}
