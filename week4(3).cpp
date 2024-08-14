#include<iostream>
using namespace std;
class Node{
public:

    Node *next=NULL;
    int data=0;
};
void insertend(Node **head,int data){
    Node *newnode=new Node();
    newnode->data=data;
    if(*head==NULL){
        *head=newnode;
        (*head)->next=*head;
        }
    else{
    Node *temp=*head;

    while(temp->next!=*head){
        temp=temp->next;
        }
        temp->next=newnode;

        newnode->next=*head;

    }
}
Node *newnode25=NULL;

void mergesort(Node *head1,Node *head2){
    Node *temp1=head1;
    Node *temp2=head2;

    do{
        if(temp1->data < temp2->data){

            insertend(&newnode25,temp1->data);
            temp1=temp1->next;

        }
        else{

            insertend(&newnode25,temp2->data);
            temp2=temp2->next;

        }
    }while(temp1!=head1 && temp2!=head2);

    if(temp2==head2){
        insertend(&newnode25,temp2->data);
        temp2=temp2->next;
    }

    do{
        insertend(&newnode25, temp1->data);
        temp1 = temp1->next;
    }while(temp1!=head1);
    do{
        insertend(&newnode25, temp2->data);
        temp2 = temp2->next;
    }while(temp2!=head2);



}
void print(Node *head){
    Node *new1=head;
    do{
        cout<<new1->data<<"->";
        new1=new1->next;
    }while(new1!=head);
}
int main(){
    Node *head1=NULL;
    Node *head2=NULL;

     insertend(&head1,1);
    insertend(&head1,5);
    insertend(&head2,4);
    insertend(&head2,6);

    mergesort(head1,head2);

    print(newnode25);

}

