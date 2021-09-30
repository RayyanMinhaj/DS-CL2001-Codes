#include<iostream>
using namespace std;

int main(){
	int arr[3][3];
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			arr[i][j]=0;
		}
	}
	
	int n=1;
	int x=0;
	int y=1;
	
	arr[x][y]=n;
	
	while(n<9){
		x=x-1;
		if(x<0){
			x=2;
		}
		y=y+1;
		if(y>2){
			y=0;
		}
		
		if(arr[x][y]!=0){
			
			x=x-1;
			if(x<0){
				x=2;
			}
			y=y-1;
			if(y<0){
				y=2;
			}
		
			n++;
			arr[x][y]=n;
		}
		
		else if(arr[x][y]==0){
			n++;
			arr[x][y]=n;
		}
		
		
		
		
		
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
