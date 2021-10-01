#include<iostream>
using namespace std;


int main(){
	int arr[4][4]={{1, 0, 0, 0},
                	{1, 1, 0, 1},
                	{0, 1, 0, 0},
                	{1, 1, 1, 1}};
                	
    int i=0,j=0;            	
    int moves=0;
                	
    while(i<=3 && j<=3){
    	if(i==3 && j==3){
    		cout<<endl<<endl<<"REACHED [3][3]"<<endl<<endl;
    		break;
		}
		else{
			
			if(arr[i][j+1]!=0){
	    		cout<<"moved right"<<endl;
	    		j=j+1;
	    		
	    		cout<<"i: "<<i<<" "<<"j: "<<j<<endl<<endl;
	    		moves++;
			}
			
			else{
				cout<<"moved down"<<endl;	
				i=i+1;
			
    			cout<<"i: "<<i<<" "<<"j: "<<j<<endl<<endl;
				moves++;
			}
			
		}
		
    	
			
			
	}
	
	
	cout<<"reached endd!!!!";
	cout<<"Num of moves: "<<moves;
    
}
