#include<iostream>
using namespace std;

class node{
	
	public:
		int data;
		node *next;
		node *prev;
	
		node(){
			data=0;
			next=NULL;
			prev=NULL;
		}
		
		node(int n){
			data=n;
			next=NULL;
			prev=NULL;
		}
};

class dlinkedlist{
	node *head;
	node *tail;
	node *last;
	node *tmp;
	node *temp;
	node *tailp;
	
	public:
		dlinkedlist(){
			head=NULL;
			tail=NULL;
		}
		
		
		void insert(int x){
			node *n=new node(x);
			
			if(head==NULL){
				head=temp;
				tail=head;
				return;
			}
			
			tail->next=n;
			n->prev=tail;
			
			tail=tail->next;
			last=tail;
			
			
		}
		
		void insert_anypos(int x, int pos){
			int count = pos;
		    // Create the ShahbaznewNode.//Take Starting address=1001
		    node* newNode = new node(x);
		    tail = head;
		    while (count != 0)
		    {
		        //cout << endl << "Yes";
		
		        tail = tail->next;
		        count = count - 1;
		        tmp = tail;
		    }
		    
			tmp = tail->next;
		    tail->next = newNode;
		    newNode->next = tmp;
		    newNode->prev = tail;
		    tmp->prev = newNode;
		}
		
		void del_node(int data1){
			 tail = head;

		    while (tail != NULL)
		    {
		        //cout <<endl<< tail->data;
		        if (tail->data == data1)
		        {
		            //        cout << "Yahoo";
		            break;
		        }
		
		        tmp = tail;
		        tail = tail->next;
		    }
			    tailp= tail->next ;
			    tmp->next = tailp;
			    tailp->prev = tmp;
			
		}
		
		void display(){
			cout << endl;
		    tmp = head;
		    while (tmp != NULL)
		    {
		        cout << " " << tmp->data;
		        tmp = tmp->next;
		    }
		
		}
		
		
			
};



int main(){
	dlinkedlist list;
	
	list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(5);
    list.display();
    list.insert_anypos(7, 2);
    list.display();
    list.del_node(2);
    list.display();
    
}






