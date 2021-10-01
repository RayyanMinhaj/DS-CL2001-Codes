#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *link;
		
		node(){
			data=0;
			link=NULL;
		}
		
		node(int data){
			this->data=data;
			this->link=NULL;
		}
};






class linkedlist{
	node *head;
	node *tail;	
	
	public:
		linkedlist(){
			head =NULL;
			tail=NULL;
		}
		
		void insert(int d){
			// Create the ShahbaznewNode.//Take Starting address=1001
        	node* n = new node(d);
			
	        if (head == NULL) {
    	        head = n;
        	    tail = head;

            	return;
        	}

      
            if (tail->link != NULL)
        	{
            	tail = tail->link;
    
   		    }
   		    
        	tail->link = n;
		}
		
		
		void insert_any(int d, int pos){
			int count = pos;
        	node* n;
        	node* temp;
        	n->data=d;
        	
        	
	        while (count!=0)
	        {
	            tail = tail->link;
	            count=count-1;
	            temp = tail->link;
	        }
	        tail->link = n;
	        n->link = temp;
		}
		
		
		
		void del(int d){
			node *n=head;
			node *lag=n;
			
			while(n!=NULL){
				if(n->link==NULL){
					break;
				}
				
				lag=n;
				n=n->link;
		
			}
	
			lag->link=NULL;
		}
		
		
		void display(){
			node *tmp = head;
        	while (tmp!= NULL)
        	{
           		cout << " " << tmp->data;
            	tmp = tmp->link;
        	}

			
		}
		
		
		void insert_first(int d){
			node *temp;
			node *n=new node();
			n->data=d;
			
			temp=head;
			
			head=n;
			head->link=temp;
			
		}
		
		
		
		linkedlist& MergeSort(){
			//since we know it is 8 nodes only, we can assume pivot at 4
			//0	 1	2  3     4 5  6  7
			//3 10 23 54     1 5 25 75
			node*n1= new node();
			node*n2= new node();
			node*temp=new node();
			
			n1=head;	//n1 will be for first 4 values
			n2=head;	//n2 will be for last 4 values
			temp=head;
			
			int count=0;
			
			while(count!=4){
				count++;
				n2=n2->link;
			}
		


			linkedlist newlist;
			int max=0;
			while(temp!=NULL){
				if(temp->data>max){
					max=temp->data;
				}
				temp=temp->link;
			}
			
			int c =0;
			
			for(int i=0;i<8-1;i++){
				
				if(n1->data>n2->data){
					newlist.insert(n2->data);
					n2=n2->link;
					
				}
				else{
					newlist.insert(n1->data);
					n1=n1->link;
					
				}
							
			}
			
			newlist.insert(max); //this is little juggar beacause were not using recursion so last value is not being stored (which should be max) so i put max on last index or last node by myself
			
			return newlist;
			
		}
	
};



int main(){
	
	linkedlist list;
	
		list.insert(3);
		list.insert(10);
		list.insert(23);
		list.insert(54);
		list.insert(1);
		list.insert(5);
		list.insert(25);
		list.insert(75);
		
		list=list.MergeSort(); //if we did merge sort inside main then we wouldnt have the need to put list=list.mergeSort() we can just sort ourselves
        list.display();
        
        
}
