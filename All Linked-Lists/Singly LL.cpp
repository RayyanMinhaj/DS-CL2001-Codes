//In memory of ShahbazNode
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
		
		
		int length(){
			node *n=new node();
			n=head;
			int count=1;
			
			while(n!=NULL){
				count++;
				n=n->link;
			}
			
			return (count-1);
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
		
		linkedlist(const linkedlist &rhs){
			node *temp=new node();
			
			temp=rhs.head;
			
			while(temp!=NULL){
				this->insert(temp->data);
				temp=temp->link;
			}
			
		}
		
		linkedlist& operator =( linkedlist &rhs){
			
			if(rhs.length()>=this->length()){
				
				int x=rhs.length()-this->length();
				x=rhs.length()-x;
				
				node *n=new node();
				n=head;
				
				node *temp=new node();
				temp=rhs.head;
				
				for(int i=0;i<x;i++){
					n->data=temp->data;
					
					n=n->link;
					temp=temp->link;
				
				}
				
				
				
				
				
				while(temp!=NULL){
					this->insert(temp->data);
					temp=temp->link;
				}
		
		
		
		
			}
			
			
			
			else{
				
				int x=this->length()-rhs.length();
				x=this->length()-x;
				
				node *n=new node();
				n=head;
				
				node *temp=new node();
				temp=rhs.head;
				
				for(int i=0;i<x;i++){
					n->data=temp->data;
					
					temp=temp->link;
					
					if(i!=x-1){
						n=n->link;
					}
					else{
						n->link=NULL;
					}	
						
				
				}	
				
			}
			
			
			
		}
		
		//array, tree, AVL 
		
		void reverse(){
			linkedlist l2;
			
			node *n=new node();
			n=head;
			
			while(n!=NULL){
				l2.insert_first(n->data);
				
				n=n->link;
			}
			
		
		
		
			node *temp=new node();
			temp=l2.head;
			
			node *n1=new node();
			n1=head;
			
			
			
			
			while(temp!=NULL){
				n1->data=temp->data;
				
				n1=n1->link;
				temp=temp->link;
			}
			
			
		}
		
		//assuming swap func is made
		// 12 3 4 5 6 7 10
		
		//list ki length= lenght()
		
		
		void reverse2(){
			node *n=new node();
			n=head;
			
			node *temp=new node();
			temp=head;
			
			for(int i=0;i<this->length();i++){
				
				while(n!=NULL){
					
					//8 75 20 9 12 15 99 XX

					
					//99 15 12 9 20 75 8
					 
					swap(temp->data,n->data);
					
					n=n->link;
					
				}
				
				temp=temp->link;
				n=temp;
				
			}
			
			
		}
		
		friend linkedlist func(linkedlist &lhs, linkedlist& rhs);
		
		
};


linkedlist& func(linkedlist &lhs, linkedlist& rhs){
			linkedlist temp;
			
			node *n=new node();
			n=lhs.head;
			
			node *n1=new node();
			n1=rhs.head;
			
			
			
			if(lhs.length()>=rhs.length()){
				while(n!=NULL){
					if(n->data==n1->data){
						temp.insert(n->data);
					}
					
					n=n->link;
					n1=n1->link;
				}
			}
			else{
				while(n1!=NULL){
					if(n1->data==n->data){
						temp.insert(n->data);
					}
					
					n=n->link;
					n1=n1->link;
				}
			}
			
		
			
			return temp;
		}
		





int main(){
	
	linkedlist list;
	linkedlist list2;
	//2, 3, 8, 9, 10, 20, 54, 75
		
		
		list.insert(10);
		list.insert(3);
		list.insert(2);
		list.insert(54);
		
		
		
		list2.insert(8);
		list2.insert(3);
		list2.insert(54);
		list2.insert(10);
		list2.insert(12);
		list2.insert(15);
		list2.insert(99);
		
		
		linkedlist list3;
		
		list3=func(list,list2);
		
		list3.display();
		
		
		
		
		//list2.reverse2();
		//list2.display();
		
		//list=list2;
		//list.display();
		
	
	
        
        //list.MergeSort(&list.head);
        //list.display();
        
        
		
//		linkedlist l2(list);
//        linkedlist l3;
//        l3=l2;
//        l3.insert(78);
//        
//        l3.display();


		
        
        
}
