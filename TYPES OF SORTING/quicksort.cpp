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
	
	cout<<"~~~QUICK SORT~~~"<<endl;
	cout<<"using first element as pivot"<<endl<<endl;
	quicksort(arr, 0, 9);
	
	for(int i=0;i<10;i++){
		cout<<arr[i]<<" ";
	}
	
}
