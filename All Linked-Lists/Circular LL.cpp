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
		}
		
		void insert(int d){
			if(head==NULL){
				node *temp=new node(d);
				temp->link=temp;
				
				head=temp;
	
				return;
			}
			
			node *temp=new node();
			temp=head;
			
			while(temp->link!=head){
				temp=temp->link;
			}
			
			node *n=new node(d);
			
			temp->link=n;
			n->link=head;
			
			

		}
		
		
		void insert_any(int d, int pos){
			if(pos==0){
				this->insert_first(d);
			}
		
			
			
			if(pos==this->length()-1){
				this->insert(d);
			}
			
			
			
			int count=0;
			node *temp=new node();
			temp=head;
			
			while(count!=pos){
				count++;
				temp=temp->link;
			}
			
			node *n=new node(d);
			n->link=temp->link;
			temp->link=n;
			
		}
		
		
		
		void del_any(int pos){
			if(pos==0){
				node *temp=new node();
				temp=head;
				
				temp=temp->link;
				head=temp;
			}
			
			if(pos==this->length()-1){
				node *temp=new node();
				temp=head;
				while(temp->link!=head){
					if(temp->link->link==head){
						break;
					}
					temp=temp->link;
				}
				
				temp->link=head;
				
			}
			
			
			node *temp=new node();
			node *lag=new node();
			temp=head;
			lag=head;
			int count=0;
			
			while(count!=pos){
				count++;
				lag=temp;
				temp=temp->link;
			}
			
			lag->link=temp->link;
			
			
		}
		
		
		
		
		int length(){
			int count=1;
			node *temp=new node();
			temp=head;
			
			while(temp->link!=head){
				count++;
				temp=temp->link;
			}
			
			return count;
		}
		
		void display(){
			node *temp=new node();
			temp=head;
			
			for(int i=0;i<this->length();i++){
				cout<<temp->data<<" ";
				temp=temp->link;
			}

			
		}
		
		void insert_first(int x){
			node *n=new node(x);
			n->link=head;
			
			node *ptr=head;
			
			while(ptr->link!=head){
				ptr=ptr->link;
			}
			
			ptr->link=n;
			head=n;
		}
		
};






int main(){
	
	linkedlist list;
	//(i) insert at end
	list.insert(15);
	list.insert(24);
	list.insert(34);
	
	//(ii) insert at first
	list.insert_first(11);
	
	//(iii) insert any
	//treating list like array with index 0, 1, 2, 3....
	list.insert_any(6,2);
	
	//(iv) delete any node
	list.del_any(2);
	
	//(v) display circular LL
	list.display();
        
        
}
