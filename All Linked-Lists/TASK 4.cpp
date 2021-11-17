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

class doubly_list{
	node* head;
	
	public:
		doubly_list(){
			head=NULL;
		}
		
		
		void insert(int x){
			if(head==NULL){
				node *temp=new node(x);
				head=temp;
				return;
			}
			
			node *temp=new node();
			temp=head;
			
			while(temp->next!=NULL){
				temp=temp->next;
			}
			
			node *n=new node(x);
			temp->next=n;
			n->next=NULL;
			n->prev=temp;
			
		}
		
		void insert_first(int x){
			node *first=new node(x);
			first->prev=NULL;
			
			node *temp;
			temp=head;
			
			first->next=temp;
			head=first;
			
			
		}
		
		void display(){
			node *temp=new node();
			temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
		
		void insert_anypos(int x, int pos){
			if(pos==0){
				this->insert_first(x);
				return;
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
			n->prev=temp;
			
			temp->next=n;
			
		}
		
		void del_any(int pos){
			if(pos==0){
				node *temp=new node();
				temp=head;
				
				head=temp->next;
				return;
			}
			
			node *temp=new node();
			temp=head;
			
			
			int count=0;
			while(count!=pos){
				count++;
				temp=temp->next;
			}
			
			temp->prev->next=temp->next;
			
		}
		
		void concat(doubly_list &list){
	
			node *n=new node();
			n=list.head;
			
			for(int i=0;i<list.length();i++){
				this->insert(n->data);
				n=n->next;
			}
		}
		
		
		int length(){
			node *temp=new node();
			temp=head;
			int count=0;
			while(temp!=NULL){
				count++;
				temp=temp->next;
			}
			
			return count;
		}
};

int main(){
	
	doubly_list L;
	doubly_list M;
	
	L.insert(5);	M.insert(9);		
	L.insert(6);	M.insert(10);
	L.insert(7);	M.insert(11);
	L.insert(8);	M.insert(12);
	
	L.concat(M);
	
	
	L.display();

	
}
