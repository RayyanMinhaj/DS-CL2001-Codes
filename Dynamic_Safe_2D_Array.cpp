#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

template <class T>
class DS2A{
	unsigned int row;
	unsigned int col;
	T *Data;
	
	
	public:
		DS2A():row(0),col(0),Data(0){
		}
		
		DS2A(int r, int c):row(r),col(c){
			Data= new T[r*c];
			
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					*(Data+((i*col)+j))=0;
				}
			}
		}
		
		
		DS2A(const DS2A&rhs){
			row=rhs.row;
			col=rhs.col;
			Data= new T[row*col];
			
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					*(Data+((i*col)+j))=*(rhs.Data+((i*col)+j));
				}
			}
		}
		
		
		
		
		T& operator ()(int i, int j){
			int offset;
			offset= (i*col)+j;
			
			return(*(Data+offset));
			
		}
		
		~DS2A(){
			if(Data){
				delete[] Data;
			}
			
			Data=0;
			row=col=0;
		}
		
		void display(){
			int offset;
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					
					
					cout<<*(Data+((i*col)+j))<<" ";
					
					
				}
				cout<<endl;
			}
		}
		
		DS2A& operator=(DS2A& rhs){
			this->row=rhs.row;
			this->col=rhs.col;
			
			this->Data=new T[row*col];
			
			
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					*(Data+((i*col)+j))=*(rhs.Data+((i*col)+j));
				}
			}
			
		}
		
		
};



int main(){
	DS2A<int> ob1(3,3);
	ob1(0,2)=6; 
	 
	DS2A<int> ob2;
	ob2=ob1; 
	 
	ob2.display();
	
}
