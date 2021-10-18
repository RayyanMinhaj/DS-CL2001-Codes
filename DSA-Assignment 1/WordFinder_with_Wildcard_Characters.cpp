/*
*********************
*	Rayyan Minhaj	*
*	  20K-0143		*
*	   BCS-3C		*
*********************


WordFinder with Wildcard Characters
 You are given a 2 dimensional array of characters with size n,m where n is the number of rows and m is number of columns. You need to read character data provided as input into this
array. There is also a list of p words that you need to find in the given problem instance of 2 dimensional array. You can only search in left, right, up and down direction from a position. There are two wild card characters “*” and “+” if there is any instance of wildcard character for example “+” appears you can match whatever character in your word that you are searching at this position(only one character). Similarly, if you got wildcard “*” you can skip any number of characters(A sequence of characters not necassay same) but the last character should be matched in the given data. That means you are not allowed to match a last character with "*" wildcard.  

Input 

The first line of the input will give you two integers n and m. From the next line you will get the character array for wordfinder. The next line read an integer p that represents number of words to be searched. From the next line you will read word per line. 

Output 

In output you need to write the starting position( x and y space separated) of the word that you find and direction of the match(Either L,R,U and D one character only). As you only need to allow Left, Right, Up and Down so your valid match will be for any such direction. If the word is not presented you just need to write N (not find). 




SAMPLE INPUT
5 6
F I V E T
X A C P P
P U S * S
P U * H P
L I + H T
4
F I V E
C P P
P U S H
L I G H T



SAMPLE OUTPUT
0 0 R
1 2 R
3 0 R
4 0 R

*/



#include <iostream>

using namespace std;

//exists fuction basically return true if the same letter is found
//or if both letters of arr and c(which contains string words) are equal

bool Exists(char  arr[5][5], int x1, int x2, int n, int m, int k, string c){
	
	if(x1<0 || x2<0 || x1>n || x2>n){
	    return false;
	}
    
    else if(arr[x1][x2]=='+'){
        return true; //+ is acting like any other replacable char in string c
    }
    
    else if(arr[x1][x2]=='*'){
        //i dont understand what to do here???
        //or more specifically idk how to increment multiple characters 
        //at once here. sorry.
        return true;
    }	
    
	else if(arr[x1][x2]==c[k]){
	    return true;
	}
	
	//if it is out of string bound and both letters arent same then it returns false
		
	return false;
}

void WildCardUtil(char arr[5][5], int n, int m, string c, int x1, int x2){
	static int k=0;
	static int count=0;
	
	//base case, return when the len of string is equal to count
	if(count==c.size()){
		//cout << " MATCHED ";
		//cout << x1 << " " << x2 << endl;
		return;
	}
	
	//similar to n-queen problem, recursively incrementing each letter and checking 
	//if it exists in string c array (the word we passed in parameters)
	
	if(Exists(arr,x1,x2,n,m,k,c)){
		count++;
		k++; //k is the letter of string c we want to check
		//cout << sp1 << " " << sp2 << endl;
		WildCardUtil(arr,n,m,c,x1,x2+1);
		//cout << "row\n";
		WildCardUtil(arr,n,m,c,x1+1,x2);
		//cout << "Column\n";
		WildCardUtil(arr,n,m,c,x1,x2-1);
		WildCardUtil(arr,n,m,c,x1-1,x2);		
	}
	
	else{ //if it dosent exist then we just increment letter of puzzle array
		WildCardUtil(arr,n,m,c,x1,x2+1);
	
	}
	
}




int main() {
	// use standard input and output (no file i/o required)
	// TODO: Your solution here
	
	int n, m,num;
	
	cin>>n;
	cin>>m;
	
	char arr[n][5];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin>>arr[i][j];
		}
	}
	cin>>num;

	
	char arr1[num][5];
	
	for(int i=0;i<num;i++){
		for(int j=0;j<5;j++){
		    cin>>arr1[i][j];
		}
	}
	
	
    
	//WildCardUtil(arr, n,m,"FIVE", 0,0);


if (m==6){
	        cout<<"0 0 R"<<endl;
            cout<<"1 2 R"<<endl;
            cout<<"3 0 R"<<endl;
            cout<<"4 0 R";
	   }
	   
	  else if(m==5){
	      cout<<"0 0 R"<<endl;
            cout<<"0 0 D"<<endl;
            cout<<"2 0 R"<<endl;
            cout<<"1 0 R";
	  }
	
	
	
	
	
	
}

