#include<iostream>
using namespace std;

void printsol(int arr[4][4]){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}


void check(int arr[4][4],int r, int c,int sol[4][4]){
	if(r==3 && c==3){
		printsol(sol);
	}
	
	if(arr[r][c+1]!=0){
		sol[r][c+1]=1;
		check(arr,r,c+1,sol);
	}
	else if(arr[r+1][c]!=0){
		sol[r+1][c]=1;
		check(arr,r+1,c,sol);
	}
}


int main(){
	int arr[4][4]={ {1, 0, 0, 0},
					{1, 1, 0, 1},
					{0, 1, 0, 0},
					{1, 1, 1, 1}};
					
	int r=0,c=0; //starting positions
		
	int sol[4][4]={{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	
	check(arr,r,c,sol);
	
	
}
