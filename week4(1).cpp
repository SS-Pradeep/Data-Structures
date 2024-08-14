#include<iostream>
using namespace std;
class Node{
public:
    Node *prev=NULL;
    Node *next=NULL;
    int data=0;
};
void insertend(Node **head,int data){
    Node *newnode=new Node();
    newnode->data=data;
     if (*head == nullptr) {
        *head = newnode;
        (*head)->prev = *head;
        (*head)->next = *head;
    } else {
        Node* last = (*head)->prev;
        last->next = newnode;
        newnode->prev = last;
        newnode->next = *head;
        (*head)->prev = newnode;
    }
}
Node *newnode1=NULL;
void sum1(Node *head,int total){
    if(head==NULL){
        return ;
    }

    Node *current=head;
    int sum=0;
    while(current->next!=head){
        current=current->next;
        sum+=current->data;
    }
    insertend(&newnode1,sum);
    total--;
    if(total > 0){

            sum1(head->next,total);
    }
}
void print(Node *head){
    if(head==NULL){
        return;
    }
    Node *new1=head;
    do{
        cout<<new1->data<<"->";
        new1=new1->next;
    }while(new1!=head);
}
int total1(Node *head){
    Node *temp=head;
    int c=1;
    while(temp->next!=head){
        temp=temp->next;
        c++;
    }
    return c;
}
int main(){
    Node *head=NULL;
    insertend(&head,10);
    insertend(&head,7);
    insertend(&head,6);
    insertend(&head,5);
    insertend(&head,22);
    int total=total1(head);
    sum1(head,total);
    print(newnode1);


}
