#include<iostream>  
using namespace std;

struct node
{  
    struct node *prev;  
    struct node *next;  
    int data;  
};  
struct node *head;  

void insertion_beginning();  
void insertion_last();  
void deletion_beginning();  
void deletion_last();  
void display();  
void search();  

int main ()  
{  
    int choice =0;  
    while(choice != 7)  
    {  
        cout << "\n*********Main Menu*********\n";  
        cout << "\nChoose one option from the following list ...\n";  
        cout << "\n===============================================\n";  
        cout << "\n1.Insert in Beginning\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search\n6.Display\n7.Exit\n";  
        cout << "\nEnter your choice?\n";  
        cin >> choice;  
        switch(choice)  
        {  
            case 1:  
                insertion_beginning();  
                break;  
            case 2:  
                insertion_last();  
                break;  
            case 3:  
                deletion_beginning();  
                break;  
            case 4:  
                deletion_last();  
                break;  
            case 5:  
                search();  
                break;  
            case 6:  
                display();  
                break;  
            case 7:  
                exit(0);  
                break;  
            default:  
                cout << "Please enter valid choice..";  
        }  
    }  
    return 0;
}  

void insertion_beginning()  
{  
    struct node *ptr,*temp;   
    int item;  
    ptr = new node;  
    if(ptr == NULL)  
    {  
        cout << "\nOVERFLOW";  
    }  
    else  
    {  
        cout << "\nEnter Item value";  
        cin >> item;  
        ptr->data=item;  
        if(head==NULL)  
        {  
            head = ptr;  
            ptr -> next = head;   
            ptr -> prev = head;   
        }  
        else   
        {  
            temp = head;   
            while(temp -> next != head)  
            {  
                temp = temp -> next;   
            }  
            temp -> next = ptr;  
            ptr -> prev = temp;  
            head -> prev = ptr;  
            ptr -> next = head;  
            head = ptr;  
        }  
        cout << "\nNode inserted\n";  
    }  
}  

void insertion_last(){
    node *ptr,*temp;
    int item;
    ptr = new node();
    if(ptr == NULL){
        cout<<"\nOVERFLOW";
    }else{
        cout<<"\nEnter value: ";
        cin>>item;
        ptr->data=item;
        if(head == NULL){
            head = ptr;
            ptr -> next = head;
            ptr -> prev = head;
        }else{
            temp = head;
            while(temp->next !=head){
                temp = temp->next;
            }
            temp->next = ptr;
            ptr ->prev=temp;
            head -> prev = ptr;
            ptr -> next = head;
        }
    }
    cout<<"\nnode inserted\n";
}

void deletion_beginning(){
    node *temp;
    if(head == NULL){
        cout<<"\n UNDERFLOW";
    }else if(head->next == head){
        head = NULL;
        delete(head);
        cout<<"\nnode deleted\n";
    }else{
        temp = head;
        while(temp -> next != head){
            temp = temp -> next;
        }
        temp -> next = head -> next;
        head -> next -> prev = temp;
        delete(head);
        head = temp -> next;
    }
}

void deletion_last(){
    node *ptr;
    if(head == NULL){
        cout<<"\n UNDERFLOW";
    }else if(head->next == head){
        head = NULL;
        delete(head);
        cout<<"\nnode deleted\n";
    }else{
        ptr = head;
        if(ptr->next != head){
            ptr = ptr -> next;
        }
        ptr -> prev -> next = head;
        head -> prev = ptr -> prev;
        delete(ptr);
        cout<<"\nnode deleted\n";
    }
}

void display(){
    node *ptr;
    ptr=head;
    if(head == NULL){
        cout<<"\nnothing to print";
    }else{
        cout<<"\n printing values ... \n";
        while(ptr -> next != head){
            cout<<ptr -> data<<endl;
            ptr = ptr -> next;
        }
        cout<<ptr -> data<<endl;
    }
}

void search(){
    node *ptr;
    int item,i=0,flag=1;
    ptr = head;
    if(ptr == NULL){
        cout<<"\nEmpty List\n";
    }else{
        cout<<"\nEnter item which you want to search?\n";
        cin>>item;
        if(head ->data == item){
            cout<<"item found at location "<<i+1;
            flag=0;
        }else{
            while (ptr->next != head){
                i++;
                if(ptr->data == item){
                    cout<<"item found at location "<<i;
                    flag=0;
                    break;
                }else{
                    flag=1;
                }
                ptr = ptr -> next;
            }
        }
        if(flag != 0)
        {
            cout<<"Item not found\n";
        }
    }
}
