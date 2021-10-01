#include<iostream>
using namespace std;


void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;
   

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
        	while(number[i]<=number[pivot]&&i<last)
            i++;
        	
			while(number[j]>number[pivot])
            j--;
        	if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
        	}
    	}

		for(int k=0;k<10;k++){
					cout<<number[k]<<" ";
				}
				cout<<endl<<endl;
		
	
    	temp=number[pivot];
    	number[pivot]=number[j];
    	number[j]=temp;
    	quicksort(number,first,j-1);
    	quicksort(number,j+1,last);

   }
}



int main(){
	int arr[10]={1,2,7,14,3,9,11,10,0,5};
	
	int n=10;
	int ch;
	
	cout<<"un-sorted array: ";
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl<<endl;
	cout<<"SORTING ALGORITHM "<<endl;
	cout<<"1. Bubble Sorting" <<endl;
	
	cout<<"2. Insertion Sorting" <<endl;
	cout<<"3. Selection Sorting" <<endl;
	cout<<"4. Comb Sorting" <<endl;
	cout<<"5. Quick Sorting" <<endl;
	
	cout<<"Enter option: ";
	cin>>ch;
	cout<<endl<<endl<<endl;
	
	if(ch==1){
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
	
	else if(ch==2){
		cout<<"~~~INSERTION SORT~~~"<<endl<<endl;

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
	
	else if(ch==3){
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
	
	else if(ch==4){
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
	
	else if (ch==5){
		cout<<"~~~QUICK SORT~~~"<<endl;
	cout<<"using first element as pivot"<<endl<<endl;
	quicksort(arr, 0, 9);
	
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	}
}
