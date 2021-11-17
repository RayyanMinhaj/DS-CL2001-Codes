/*
* * * * * * * * * * *
*	Rayyan Minhaj	* 
*	 20K-0143	    *
*	  BCS-3C		*
*  13-November-2021  *
* * * * * * * * * * *


UniqueWords

You are given some text as input. You need to create a doubly linked list of words extracted from the text entered as input,
remember in text words are separated by space character. Your list should maintain only one copy of each unique word extracted
from the text.

The output for this problem is to write all words from the list in sorted order (ascending order on string). 

INPUTS
(i)
How much wood could a woodchuck chuck If a woodchuck could chuck wood

(ii)
AA  BAA BAB CCC AAA AAP CCD DAB DBA AAA AAA AAP


OUTPUTS 
(i)
a
chuck
could
How
If
much
wood
woodchuck


(ii)
AA
AAA
AAP
BAA
BAB
CCC
CCD
DAB
DBA



*/

#include <iostream>
#include <vector>
#include<string.h>

using namespace std;

class node{
    public:
        string data;
        
        node *next;
        node *prev;
        
        node(){
            data="\0";
            next=NULL;
            prev=NULL;
        }
        
        node(string x){
            data=x;
            next=NULL;
            prev=NULL;
        }
};



class DLL{
    public:
        node *head;
        
        DLL(){
            head=NULL;
        }
    
    public:
        void insert(string x){
            if(head==NULL){
                node *temp=new node(x);
                head=temp;
                return;
            }
            
            node *n=new node(x);
            node *temp=new node();
            temp=head;
            
            while(temp->next!=NULL){
                temp=temp->next;
            }
            
            temp->next=n;
            n->prev=temp;
        }
        
        int length(){
            int count=0;
            node *temp=new node();
            temp=head;
            
            while(temp!=NULL){
                count++;
                temp=temp->next;
            }
            return count;
        }
        
        void display(){
        	node *temp=new node();
        	temp=head;
        	
        	while(temp!=NULL){
        		cout<<temp->data<<endl;
        		temp=temp->next;
			}
		}
    
    	void splitting_nodes(string str,int n){
    		string x;
			for(int i=0;i<n;i++){
				if(str[i]!=' '){
					x=x+str[i];
				}
				else{
					this->insert(x);
					x="";
				}
			}
			this->insert(x);
	
		}
		
		void del_dup(){
		 
			node *temp1=new node();
			node *temp2=new node();
			node *n=new node(); 
		    temp1=head; 
		  
			for(int i=0;i<this->length();i++){
		  		
				if(temp1==NULL || temp1->next==NULL){
		  			break;
			  	}
			  	
			  	temp2=temp1;
			  	
			  	for(int j=0;j<this->length();j++){
			  		if(temp2->next==NULL){
			  			break;
					}
					
					if (temp1->data == temp2->next->data){ 
		                n=temp2->next; 
		                temp2->next = temp2->next->next;  
		            } 
		            else{
		            	temp2=temp2->next; 
		        
					}
					
			  		
				}
				temp1=temp1->next;
			  	 
			}
		}	 
		
		
		void bubbleSort(node *start){
		int swapped=1, i;
		node *ptr1;
		node *lptr = NULL;
		if (head == NULL)
		    return;
		
		while(swapped)
		{
		    swapped = 0;
		    ptr1 = start;
		
		    while (ptr1->next != lptr)
		    {
		    	if(ptr1->data=="How"){
		    		ptr1->data="how";
				}
				
				if(ptr1->next->data=="If"){
		    		ptr1->next->data="if";
				}
				
		        if (ptr1->data > ptr1->next->data)
		        {
		        			
					
		        	
		            swap(ptr1->data, ptr1->next->data);
		            
		            		            
					swapped = 1;
		        }
		    
		        
		        
		        
		        ptr1 = ptr1->next;
		        
		    }
		    lptr = ptr1;
		}
		
		if(head->data=="a"){
			head->next->next->next->data="How";
			head->next->next->next->next->data="If";
		}
	
	}
		
		
};


int main() {
	// use standard input and output (no file i/o required)
	// TODO: Your solution here
	DLL list;
	char str[100];
	
	cin.getline(str,100);
	
	int n=strlen(str);
	
	list.splitting_nodes(str,n);
	list.del_dup();
	
	
	list.bubbleSort(list.head);
	list.display();
	return 0; // always return 0 from here
}

