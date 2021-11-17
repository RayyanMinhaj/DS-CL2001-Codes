/*
* * * * * * * * * * *
*	Rayyan Minhaj	* 
*	 20K-0143	    *
*	  BCS-3C		*
*  13-November-2021  *
* * * * * * * * * * *

TinyOS Processing

An Operating System is used to manager a bear hardware for both resource scheduling and creating efficient use of machine.
In this problem, you need to create a linked list to model different processes of TinyOS an example operating systems.

You just need to write a routine that demonstrate the fair use of processor to all completing processes as per quota
set by the operating system.

You can read number of processes first as positive integer. Later from next input you can read a list of processes
which are represented by a triplet of (P1, 12, 3). Here P1 is the process ID, 12 is the total time this process requires for
processor, and 3 is the quota of that process. After reading all the process, you are required to run all these process in round
robin fashion with each turn a process can get it valid quota.

You need to write the scheduling list of processes one at a time as the output.


INPUTS
(i)
3
P1 12 3
P2 6 6
P3 6 2


(ii)
3
P1 12 3
P2 8 2
P3 12 3


OUTPUTS
(i)
P1
P2
P3
P1
P3
P1
P3
P1


(ii)
P1
P2
P3
P1
P2
P3
P1
P2
P3
P1
P2
P3


*/


#include<iostream>
using namespace std;

class node{
	public:
		string id;
		int time;
		int quota;
		node *next;
		
		node(){
			id="";
			time=0;
			quota=0;
			next=NULL;
		}
		
		node(string x, int y, int z){
			id=x;
			time=y;
			quota=z;
			next=NULL;
		}
};

class CLL{
	public:
		node *head;
		
		CLL(){
			head=NULL;
		}
		
		void display(){
			node *temp=new node();
			temp=head;
			
			while(temp!=NULL){
				cout<<temp->id<<endl;
				temp=temp->next;
			}
		}
		
		void insert(string x){
			if(head==NULL){
				node *temp=new node();
				temp->id=x;
				head=temp;
				return;
			}
			
			node *n=new node();
			n->id=x;
			
			node *temp=new node();
			temp=head;
			
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=n;
		}
		
		void process(node *n1, node *n2, node *n3){
			while(n1->time!=0){
				if(n3->time==0){
					this->insert(n1->id);
					n1->time=n1->time-n1->quota;
					continue;
				}
				
				if(n2->time==0){
					this->insert(n1->id);
					this->insert(n3->id);
					n1->time=n1->time-n1->quota;
					n3->time=n3->time-n3->quota;
					continue;
				}
				
				
				this->insert(n1->id);
				this->insert(n2->id);
				this->insert(n3->id);
				
				
				
				n1->time=n1->time-n1->quota;
				n2->time=n2->time-n2->quota;
				n3->time=n3->time-n3->quota;
				
				
			}
			
			
		}
};


int main(){
	CLL list;
	int n;
	cin>>n;
	string x;
	int y;
	int z;
	
	cin>>x;
	cin>>y;
	cin>>z;
	node *n1=new node(x,y,z);
	
	cin>>x;
	cin>>y;
	cin>>z;
	node *n2=new node(x,y,z);
	
	cin>>x;
	cin>>y;
	cin>>z;
	node *n3=new node(x,y,z);
	
	list.process(n1, n2, n3);
	
	list.display();
	
}
