//vaibhav doubly linked list
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructor
    Node(int d){
    this -> data = d;
    this -> next = NULL;
    this -> prev = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << value << endl;
    }
};

void print(Node* head){
    Node* temp = head;

    while(temp!=NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head){
    int len=0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail, int d){
    //empty list
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    
    else{
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
}

void insertAtTail(Node* &tail, Node* &head, int d){

  if(tail == NULL){
    Node* temp = new Node(d);
    tail = temp;
    head = temp;
  }  
  
  else{
  Node* temp = new Node(d);
  tail -> next = temp;
  temp -> prev = tail;
  tail = temp;
  }
}

void insertAtPosition(Node* &tail, Node* &head, int position, int d){

   //insertAtStart
   if(position == 1){
      insertAtHead(head, tail, d);
      return;
   }
   
   Node* temp = head;
   int count = 1;

   while (count < position -1){
    temp = temp -> next;
    count ++;
   }

   //insertAtLast
   if (temp -> next == NULL){
    insertAtTail(tail, head,d);
    return;
   }

   //insertAtMiddle
   Node* nodeToInsert = new Node(d);
   nodeToInsert -> next = temp -> next;
   temp -> next -> prev = nodeToInsert;
   temp -> next = nodeToInsert;
   nodeToInsert -> prev = temp;

}

void deleteNode(Node* &head,Node* &tail,int position)
{   
    //deletion of starting node
    if(position==1)
    {
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;    
    }

    else
    {
       Node* curr = head;
       Node* prev = NULL;
       int cnt=1;
       while(cnt<position){
         prev=curr;
         curr=curr->next;
         cnt++;
   }
        //for tail deletion 
        if(curr->next==NULL)
        {
            tail=prev;
            prev->next=curr->next;  // null
            curr->prev=NULL;
            delete curr;
            return ;
        }
        // below case only execute when position is not head or tail
        curr->next->prev=curr->prev;
        prev->next=curr->next;
        curr->next=NULL;
        curr->prev=NULL;

        delete curr;
    }

}

int main(){
 
 Node* head = NULL;
 Node* tail = NULL;
 print(head);
 cout << getLength (head) << endl;
 insertAtHead(head,tail,11);
 print(head);
 insertAtTail(tail, head, 25);
 print(head);
 insertAtPosition(tail, head, 2, 100);
 print(head);
 deleteNode(head, tail, 2);
 print(head);

}


