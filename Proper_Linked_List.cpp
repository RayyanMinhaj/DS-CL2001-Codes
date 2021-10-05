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
		
	
	public:
		node *head;
		node *tail;
	
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
		
		
		void length(){
			node *n=new node();
			n=head;
			int count=1;
			
			while(n!=NULL){
				count++;
				n=n->link;
			}
			
			cout<<"length: "<<count;
		}
		
		
		
		node* MergeSortedList(node *lst1, node *lst2){
			node *result;
			
			//base case
			if(lst1==NULL){
				return lst2;
			}
			else if(lst2==NULL){
				return lst1;
			}
			
			
			//recursively merging two lists
			
			if(lst1->data <= lst2->data){
				result=lst1;
				result->link = MergeSortedList(lst1->link,lst2);
			}
			else{
				result=lst2;
				result->link = MergeSortedList(lst1, lst2->link);
			}
			
			return result;
			
		}
		
		
		//func for splitting till we reach 1 element
		
		void SplitList(node *source, node** front, node** back){
			node *ptr1=new node();
			node *ptr2=new node();
			
			ptr2=source;
			ptr1=source->link;
			
			while(ptr1!=NULL){
				ptr1=ptr1->link;
				
				if(ptr1!=NULL){
					ptr2=ptr2->link;
					ptr1=ptr1->link;
				}
			}
			
			*front=source;
			*back=ptr2->link;
			ptr2->link=NULL;
		}
	
		
		void MergeSort(node** thead){
			
			head=*thead;
			node* ptr1;
			node* ptr2;
			
			//base case
			if(head==NULL || head->link==NULL){
				return;
			}
			
			SplitList(head, &ptr1, &ptr2);
			
			//recursively sorting lists
			MergeSort(&ptr1);
			MergeSort(&ptr2);
			
			*thead=MergeSortedList(ptr1,ptr2);
		}
};





int main(){
	
	linkedlist list;
	
	//2, 3, 8, 9, 10, 20, 54, 75
		
		list.insert(10);
		list.insert(3);
		list.insert(2);
		list.insert(54);
		list.insert(8);
		list.insert(75);
		list.insert(20);
		list.insert(9);
		
		//list.length();
		//list.display();
        
        list.MergeSort(&list.head);
        list.display();
        
        
        
}
