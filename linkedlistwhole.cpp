   ////////////////////////////////
  //	Rayyan Minhaj 20K-0143 	//
 //		    BCS-3C			   //
////////////////////////////////		

//1. DISPLAY FUNC
//2. DELETE NODE AT ANY POS
//3. DELETE LAST NODE
//4. INSERT FROM END
//5. INSERT INTO ANY POS
//6. CHECKING IF PALINDROME (ONLY FOR 5 NODES)
//7. LENGTH OF LIST
//8. REVERSING A LIST


#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *link;
		
		
};

void display(node *n){
	while(n!=NULL){
		cout<<n->data<<" ";
		n=n->link;
	}
}

void delnode_anypos(node *n, int a){
	node *lag=n;
	node *temp;
	
	while(n!=NULL){
		if(n->data==a){
			n=n->link;
			temp=n;
			lag->link=temp;
		}
		
		lag=n;
		n=n->link;
	}
	
}


void insert(node *n, int a) //if these were member functions we wouldnt need to put node *n in parameters, just doing rn for my ease
{
	node *temp=NULL;
	temp=new node();
	temp->data=a;
	temp->link=NULL;
	
	while(n!=NULL){
		if(n->link==0){
			break;
		}
		
		n=n->link;
	}
	
	n->link=temp;
	
	
}


void insert_anypos(node *n, int pos, int val){
	//can put a check here for if pos has to be greater than 0 (meaning not first position)
	int count=1;
	node *temp=NULL;
	temp=new node();
	node *lag=n;
	
	while(n!=NULL){
		if(count==pos){
			lag=n;
			n=n->link;
			
			temp->data=val;
			temp->link=n;
			lag->link=temp; 
			break;
		}
		
		count++;
		
		lag=n;
		n=n->link;
	}
	
	
}



void palindrome_check(node *n){	
	node *head=n;
	node *last;
	node *lag=n;
	
	
	while(n!=NULL){
		if(n->link==NULL){
			last=n;
			break;
		}
		lag=n;
		n=n->link;
	}
	
	//now head is beginning node and last is last node
	
		if(head->data==last->data && head->link->data==lag->data){
			cout<<"YES PALINDROME";
		}
		else{
			cout<<"NOT PALINDROME";
		}
	
}

void length_of_list(node *n){
	int count=0;
	
	while(n!=NULL){
		n=n->link;
		count++;
	}
	cout<<endl<<endl<<"NUM OF NODES: "<<count;
}

void del_last(node *n){
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

void reverse(node *n){
	int arr[5]; //because 5 nodes
	int i=0;
	
	node *head=n;
	
	while(n!=NULL){
		arr[i]=n->data;
		
		i++;
		n=n->link;
	}
	
	
	for(int j=4;j>=0;j--){
		head->data=arr[j];
		//cout<<head->data<<" ";
		head=head->link;
	}
	
	
	
}

int main(){
	node *head=NULL;
	node *second=NULL;
	node *third=NULL;
	node *fourth=NULL;
	
	
	head=new node();
	second= new node();
	third=new node();
	fourth=new node();
	
	head->data=1;
	head->link=second;
	
	second->data=2;
	second->link=third;
	
	third->data=3;
	third->link=fourth;
	
	fourth->data=4;
	fourth->link=NULL;
//	
//	delnode_anypos(head, 2); //THIS ONLY WORKS FOR MIDDLE VALUES, CANT POP FIRST AND LAST WITH THIS!!! working on a fix :P
//	display(head);
//	
	insert(head, 5); //inserts at end
	cout<<"IN THE BEGINNING: "<<endl;display(head);
	
//	cout<<"INSERTING 55 AT SECOND POSITION: "<<endl;
//	insert_anypos(head, 2, 55); //inserted new node of 55 value at 2nd position :DDD
//	

	cout<<endl<<endl;
	//INSIDE LIST: 1 2 3 4 5
	palindrome_check(head); //for 5 integers or 5 nodes ONLY right now
	
	
	length_of_list(head);
	
	del_last(head);  //deletes last node
	cout<<endl<<endl<<"LAST NODE DELETED: "<<endl;
	display(head);
	
	insert(head, 76);
	cout<<endl<<endl<<"RE-INSERTING LAST NODE: "<<endl;
	display(head);
	
	cout<<endl<<endl<<"REVERSING LIST"<<endl;
	reverse(head);
	display(head);
	
}
