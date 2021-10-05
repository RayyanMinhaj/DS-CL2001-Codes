/*

* * * * * * * * * * *
*	Rayyan Minhaj	* 
*	 20K-0143	    *
*	  BCS-3C		*
*  02-October-2021  *
* * * * * * * * * * *



Complete a partially solved 9x9 Sodoku puzzle. An example of a solved 9x9 puzzle is given below in Figure A. A valid solution must follow these rules, 

	1. Each row must contain the digits 1-9 without repetition. 
	2. Each column must contain the digits 1-9 without repetition. 
	3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition. 
You are given the solution for the first 8x8 grid.
Your task is to fill the last row and last column to complete the 9x9 solution, which means you have to fill in 17 values.
The places for those values are highlighted in red in Figure B below.


Use dynamic array to solve the problem. You can read the input file in a DynamicSafe2dArray and then append row and column. 

Input file: The first row contains first eight elements of first row of the puzzle. Similarly, the subsequent rows contain first eight elements of subsequent rows of the
puzzle up to the eighth row. For each row, elements are separated by a space. 

Output file: It contains the complete 9x9 solution of the puzzle. The first row contains the first complete row of the puzzle. Similarly, the subsequent rows contain complete
subsequent rows of the puzzle up to the ninth row. Row elements are separated by a space. 



INPUT:
5 3 4 6 7 8 9 1
6 7 2 1 9 5 3 4
1 9 8 3 4 2 5 6
8 5 9 7 6 1 4 2
4 2 6 8 5 3 7 9
7 1 3 9 2 4 8 5
9 6 1 5 3 7 2 8
2 8 7 4 1 9 6 3

OUTPUT:
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
*/






#include <iostream>

using namespace std;

int main() {
	// use standard input and output (no file i/o required)
	// TODO: Your solution here

	int arr[9][9];
	bool flag[9]={false,false,false,false,false,false,false,false,false}; //used to figure out which element is not present in row (and col?)
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=0;i<9;i++){
		arr[8][i]=0;
	}
	
	for(int i=0;i<9;i++){
		arr[i][8]=0;
	}
	
	
	
	int x;

	for(int i=0;i<8;i++){
		x=0;
		
		
		
		for(int k=0;k<9;k++){
			
			flag[(arr[i][k])-1]=true;
			
		}
		
		
	
		
		for(int k=0;k<9;k++){
			if(flag[k]==false){
				x=k+1;
				break;
			}
		}
			
		
		arr[i][8]=x;
		
		
		
		
		
		for(int k=0;k<9;k++){
			flag[k]=false;
		}
			
				
	}
	
	
	
	for(int i=0;i<9;i++){
		x=0;
		
		
		
		for(int k=0;k<9;k++){
			
			flag[(arr[k][i])-1]=true;
			
		}
		
		
	
		
		for(int k=0;k<9;k++){
			if(flag[k]==false){
				x=k+1;
				break;
			}
		}
			
		
		arr[8][i]=x;
		
		
		
		
		
		for(int k=0;k<9;k++){
			flag[k]=false;
		}
		
		
		
				
	}
	

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	

	return 0; // always return 0 from here
}

