/*
* * * * * * * * * * *
*	Rayyan Minhaj	* 
*	 20K-0143	    *
*	  BCS-3C		*
*  13-November-2021  *
* * * * * * * * * * *

Polynomial Using LinkedList
Polynomial are abstract mathematical concept generally used in algebra. A polynomial comprises of terms and each term is defined
as coefficent, variable and exponents of the variable. For example: 3X^2 is a term in which 3 is a coefficieent, X is a variable
and 2 is the exponent. A polynomial can be comprises of many terms.

You will be entered the number of terms in first polynomial and after reading it, you will be reading each term of the
polynomial as a triplet, for example 3 X 2. After reading first polynimal, you can read the second polynomial in the similar
fashion. These polynomial terms are not in sorted order of their exponents.

You are required to create a linked list of your choice to process these two polynomails. After reading these polynomials
you are required to perform addition of these polynomials, after that you are required to write the resultant polynomial in
increasing order of exponents for each variable. 

INPUTS 
(i)
3
2 X 3
1 X 2
3 X 1
2
3 X 3
2 X 1


(ii)
3
2 X 2
4 X 1
4 X 0
3
2 X 2
3 Y 2
4 X 0






OUTPUTS
(i)
3
5 X 1
1 X 2
5 X 3



(ii)
4
8 X 0
4 X 1
4 X 2
3 Y 2

*/
#include <iostream>
#include <vector>
using namespace std;

class node{
    public:
        int num;
        char co;
        int expo;
        node *next;
        node *prev;
        
        node(){
            num=0;
            co='0';
            expo=0;
            next=NULL;
            prev=NULL;
        }
        
        node(int x, char y, int z){
            num=x;
            co=y;
            expo=z;
            next=NULL;
            prev=NULL;
        }
};

class LL{
    public:
        node *head;
        
        LL(){
            head=NULL;
        }
        
        void insert(int x, char y, int z){
            if(head==NULL){
                node *temp=new node(x,y,z);
                head=temp;
                return;
            }
            
            node *n=new node(x,y,z);
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
        		cout<<temp->num<<" ";
        		temp=temp->next;
			}
		}
        
        
        void add(LL &list1, LL &list2){
            node *temp1=new node();
            node *temp2=new node();
            
            temp1=list1.head;
            temp2=list2.head;
            int ins=0;
            
            for(int i=0;i<list1.length();i++){
            	ins=0;
            	temp2=list2.head;
            	
            	for(int j=0;j<list2.length();j++){
            		
            		if(temp1->co==temp2->co && temp1->expo==temp2->expo){
            			int x=temp1->num+temp2->num;
            			this->insert(x,temp1->co,temp1->expo);
            			
            			temp2->num=0;
						ins++;
						
						break;
            			
					}
					
					temp2=temp2->next;	
            			
				}
				
				if(ins==0){
					this->insert(temp1->num,temp1->co,temp1->expo);
				}
				temp1=temp1->next;
				
				
			}
            
            
            
            node *temp=new node();
			temp=list2.head;
			
			while(temp!=NULL){
				if(temp->num!=0){
					this->insert(temp->num,temp->co,temp->expo);
				}
				temp=temp->next;
			}
            
            
            
     
        }
        
        
        
        void display2(){
            cout<<this->length()<<endl;
            
            node *temp=new node();
            temp=head;
            
            
            while(temp!=NULL){
                cout<<temp->num<<" "<<temp->co<<" "<<temp->expo<<endl;
                temp=temp->next;
            }
            
        }
        
        
        
        
    void bubbleSort(){
		int swapped, i;
		node *ptr1;
		node *lptr = NULL;
		if (head == NULL)
		    return;
		
		do
		{
		    swapped = 0;
		    ptr1 = this->head;
		
		    while (ptr1->next != lptr)
		    {
		        if (ptr1->expo > ptr1->next->expo && ptr1->co >= ptr1->next->co)
		        {
		            swap(ptr1->num, ptr1->next->num);
		            swap(ptr1->expo, ptr1->next->expo);
					swap(ptr1->co, ptr1->next->co);
		            		            
					swapped = 1;
		        }
		        ptr1 = ptr1->next;
		    }
		    lptr = ptr1;
		}
		while (swapped);
	}
        
};


int main() {
    LL list1;
    LL list2;
    LL list3;
    
    int n,m;
    cin>>n;
    
    int x;char y;int z;
    
    for(int i=0;i<n;i++){
        cin>>x;
        cin>>y;
        cin>>z;
        
        list1.insert(x,y,z);
    }
    cin>>m;
   
    
    for(int i=0;i<m;i++){
        cin>>x;
        cin>>y;
        cin>>z;
        
        list2.insert(x,y,z);
    }
    
        
    list3.add(list1,list2);
    list3.bubbleSort();
    list3.display2();
    	
    
    
	return 0; 
}

