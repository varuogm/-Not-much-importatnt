#include<bits/stdc++.h>
typedef long long ll;
#define endl "\n"
using namespace std;


class node {
public:
    int data;
    node* next;

    node(int val){
      data= val;
      next=NULL;
    }
};


void insertAtTail(node * &head , int val) {

  node* n =new node(val); //isko add karna he 

  if(head==NULL){
    head = n;
    return;
  }

  node* temp = head; //iterate ke liye temp

  while(temp->next != NULL)
  {
    temp =temp->next;
  }

  temp->next= n; //last posiiton me daldo n
}

void display(node* head) {
 // node* temp = head;
  while(head != NULL)
  {
    cout<< head->data<<"->";
    head=head->next;
  }
}

void deleteAtHead(node* &head){
  node* todelete= head;//head ko defernce kardia todelte bolke
  head= head->next;

delete todelete;
}

void deletion(node* &head ,int val){

if(head==NULL) //agar khali ho 
  return;

if(head->next==NULL){//agar ek hi ho
  deleteAtHead(head);
  return;
}

  node* temp=head;
  while(temp->next->data!=val)
    {
      temp=temp->next;
    }

  node * todelete = temp->next;
  temp->next = temp->next->next;
  delete todelete;

}

node* reverse(node* &head){
   node* prevptr =NULL;
   node* currptr = head;
   node* nextptr;

   while(currptr != NULL){

    nextptr = currptr->next;
    currptr->next=prevptr;

    prevptr=currptr;
    currptr=nextptr;
   }
return prevptr;
 }


void makeCycle(node* &head , int pos){

  node* temp=head;
  node* startNode;

  int cnt=1;
  while(temp->next!=NULL)
  {
          if(cnt==pos){
            startNode=temp;
          }

    temp=temp->next;
    cnt++;
  }
temp->next= startNode;
}


bool detectCycle(node* &head){

  node* slow=head;
  node* fast= head;

  while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;

    if(fast==slow){
      return true;
    }
  }
  return false;
 }



int main() {

node * head=NULL;

insertAtTail(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
insertAtTail(head,4);
makeCycle(head,3);
cout<<detectCycle(head)<<endl;
//deleteAtHead(head);
//deletion(head,3);
//node* newhead = reverse(head);

//display(newhead);

}
