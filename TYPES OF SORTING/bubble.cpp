#include<iostream>
using namespace std;

int main(){
	char arr[]={'A','S','O','R','T','I','N','G','E','X','A','M','P','L','E'};
	
	char temp;
	cout<<"~~~BUBBLE SORT~~~"<<endl<<endl;

	
	for(int i=0;i<15-1;i++){
		for(int j=0;j<15-i-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				
//				for(int k=0;k<10;k++){
//					cout<<arr[k]<<" ";
//				}
//				cout<<endl<<endl;
			}
			
			
			
			
		}
	}
	
	
	for(int i=0;i<15;i++){
		cout<<arr[i]<<" ";
	}
	
}

