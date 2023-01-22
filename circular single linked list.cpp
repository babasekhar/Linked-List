#include <iostream>
using namespace std;

struct Node 
{
   int data;
   struct Node *next;
};

class csllist
{
	Node  *head;
    public:
    	csllist() // default constructor. Initializing head pointer
        {
         head = NULL;
        }
        void insert_first();
        void insert_last();
        void delete_first();
        void delete_last();
        void display_list();
		int length();    
};


Node* head = NULL;

void csllist::insert_first() 
{
   	int val;
	cout<<"Enter a value to insert: ";
	cin>>val;
	
	Node *newNode = new Node;
   	newNode->data = val;
   	  
	Node *ptr = head;

   	if (head!= NULL) 
   	{
      	while (ptr->next != head)
      	{
      		ptr = ptr->next;
		}
      	ptr->next = newNode;
      	newNode->next = head;
   	} 
   	else
   	{
   		newNode->next = newNode;	
	} 
	head = newNode;		
}

void csllist::insert_last() 
{
	int val;
	cout<<"Enter a value to insert: ";
	cin>>val;
   	Node *newNode = new Node;
   	Node *ptr = head;
   	newNode->data = val;
   	newNode->next = head;
   	if (head!= NULL) 
   	{
      	while (ptr->next != head)
      	{
      		ptr = ptr->next;
		}
      	ptr->next = newNode;
   	} 
   	else
   	{
   		newNode->next = newNode;
   		head = newNode;
	} 		
}

//function to delete node from the start of the list
void csllist::delete_first()	
{
    Node *prev = head;

    if (head == NULL) 							
        cout << "List is empty" << endl;
    else if (head->next==head) //if only one node is present in the list									
        head = NULL;
	else
	{
		while (prev->next != head)
    	{
        	prev = prev->next;
    	}
	}
    prev->next = head->next;
    prev=head;
    head = head->next; //got the new head
	delete prev;
}

void csllist::delete_last()	 
{
    Node *prev = head;

    if (head == NULL) 							
        cout << "List is empty" << endl;

    else if (prev->next == prev) //if only one node is present in the list									
        head = NULL;
	else
	{
		while (prev->next->next != head)
    	{
        	prev = prev->next;
    	}
	}
	Node *last=prev->next;
    prev->next = head;    
	delete last;
}


void csllist::display_list() 
{
   Node* ptr= head;
   do{
      	cout<<ptr->data <<" ";
      	ptr = ptr->next;
   	} while(ptr != head);
}

int csllist::length()						
{
    Node *temp;
    int count = 0;
    if (head == NULL)								
    {
        return 0;
    }
    temp = head;
    do											
    {											
        temp = temp -> next;
        count++;
    } while (temp != head);
    return count;
}

int main() 
{
   	int choice, nodes, element, position, val, i;
    csllist csll;
    csllist *head = NULL;
    while (1)
    {
        cout<<endl<<"---------------------------------"<<endl;
        cout<<endl<<"Operations on singly linked list"<<endl;
        cout<<endl<<"---------------------------------"<<endl;
        cout<<"1.Insert a node at the beginning"<<endl;
        cout<<"2.Insert a node at the end"<<endl;
        cout<<"3.Delete the first  node"<<endl;
        cout<<"4.Delete the last node"<<endl;
        cout<<"5.Display the Linked List"<<endl;
        cout<<"6.Find the length of the linked list"<<endl;
        cout<<"7.Exit "<<endl;
        
		cout<<"Enter your choice : ";
        cin>>choice;
        
		switch(choice)
        {
        case 1:
            cout<<"Inserting a node at the Beginning:"<<endl;
            csll.insert_first();
            cout<<endl;
            break;
        case 2:
            cout<<"Inserting a node at the end:"<<endl;
            csll.insert_last();
            cout<<endl;
            break;
        case 3:
        	cout<<"Deleting the first node:"<<endl;
			csll.delete_first();
			break;
		case 4:
        	cout<<"Deleting the last node:"<<endl;
			csll.delete_last();
			break;	
        case 5:
            cout<<"Displaying all the nodes of the linked list:"<<endl;
            csll.display_list();
            cout<<endl;
            break;
        case 6:
            cout<<"Length of the Linked List:"<<csll.length();
            cout<<endl;
            break;  
        case 7:
            cout<<"Exiting..."<<endl;
            exit(1);
            break;  
        default:
            cout<<"you have entered a Wrong choice."<<endl;
        }
    }
    return 0;
}
