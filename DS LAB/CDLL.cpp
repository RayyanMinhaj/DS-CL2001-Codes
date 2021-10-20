#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;
	node* prev;
	
	public:
		node(){
			data=0;
			next=NULL;
			prev=NULL;
		}
		
		node(int data){
			this->data=data;
			next=NULL;
			prev=NULL;
		}
};

class circular_doubly_list{
	node* head;
	
	public:
		doubly_list(){
			head=NULL;
		}
		
		
		void insert(int x){
			
			if(head==NULL){
				node *temp=new node(x);
				temp->next=temp;
				temp->prev=temp;
				head=temp;
				return;
				
			}
			
			node *temp=new node();
			temp=head;
			
			while(temp->next!=head){
				temp=temp->next;
			}
			
			node *n=new node(x);
			temp->next=n;
			n->prev=temp;
			
			n->next=head;
			head->prev=n;
			
			
			
		}
		
		
		
		
		
		
		
		void insert_first(int x){
			node *n=new node();
			n=head;
			while(n->next!=head){
				n=n->next;
			}
			node *first = new node(x);
			node *temp= new node();
			
			n->next=first;
			
			temp=head;
			
			first->next=temp;
			first->prev=n;
			
			head=first;
			
		}
		
		void display(){
			node *temp=new node();
			temp=head;
			
			for(int i=0;i<this->length();i++){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		
		
		
		
		
		void insert_anypos(int x, int pos){
			if(pos==0){
				this->insert_first(x);
				return;
			}
			
			if(pos==this->length()-1){
				this->insert(x);
			}
			
			int count=0;
			node *temp=new node();
			temp=head;
			while(count!=pos){
				count++;
				temp=temp->next;
			}
			
			
			node *n=new node(x);
			
			n->next=temp->next;
			temp->next->prev=n;
			
			temp->next=n;
			n->prev=temp;
			
			
			
			
		}
		
		void del_any(int pos){
			if(pos==0){
				node *temp=new node();
				temp=head;
				
				head=temp->next;
				return;
			}
			
			int count=0;
			node *temp=new node();
			temp=head;
			
			while(count!=pos){
				count++;
				temp=temp->next;
			}
			
			temp->prev->next=temp->next;
			
			temp->next->prev=temp->prev;
			
		}
		
		int length(){
			int count=1;
			node *temp=new node();
			temp=head;
			
			while(temp->next!=head){
				count++;
				temp=temp->next;
			}
			
			return count;
		}
};

int main(){
	
	circular_doubly_list list;
	
	//(i) insert at end
	list.insert(5);
	list.insert(6);
	list.insert(7);
	list.insert(7);	
	
	//(ii) insert first
	list.insert_first(23);
	
	///(iii) insert anywhere
	list.insert_anypos(222,2);
	
	
	//(iv) delete any pos
	list.del_any(2);
	
	//(v) display circular doubly LL
	list.display();
	
}
