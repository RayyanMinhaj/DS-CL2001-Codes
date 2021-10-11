#include<iostream>
using namespace std;

template<class T>
class node{
	public:
		node *prev;
		T data;
		node *next;
		
		node(){
			prev=NULL;
			next=NULL;
			data=0;
		}
		
		node(T d){
			prev=NULL;
			next=NULL;
			data=d;
		}
};

template<class T>
class linkedlist{
	public:
		node<T> *head;
		node<T> *tail;
	
		linkedlist(){
			head=NULL;
			tail=NULL;
		}
		
		
		int insert(T d){
			if(head==NULL){
				node<T> *n=new node<T>;
				n->data=d;
				n->prev=NULL;
				n->next=NULL;
				
				head=n;	
				return 0;
			}
			
			node<T> *n=new node<T>;
			node<T> *temp=new node<T>;
			
			n=head;
			
			while(n->next!=NULL){
				n=n->next;
			}
			
			temp->data=d;
			n->next=temp;
			temp->next=NULL;
			
			temp->prev=n;
			n->prev=NULL;
			
			
			
		}
		
		
		void display(){
			node<T> *n=new node<T>;
			n=head;
			while(n!=NULL){
				cout<<n->data<<" ";
				n=n->next;
			}
		}
	
};



int main(){
	linkedlist<int> list1;
	list1.insert(5);
	list1.insert(2);
	list1.insert(6);
	
	list1.display();
	
	
	return 0;
}
