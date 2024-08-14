#include<iostream>
using namespace std;
class Node{
public:
    Node *next=NULL;
    int data=0;
    string ID,Name;
};
void insertend(Node **head,int data,string ID,string Name){
    Node *newnode=new Node();
    newnode->data=data;
    newnode->ID=ID;
    newnode->Name=Name;

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

void task(Node *head){
    Node *temp=head;
    while(temp!=NULL){
        temp->data=temp->data-1;

        cout<<"Task of "<<temp->ID;
        cout<<endl;
        temp=temp->next;
        if(temp->data==0){
            cout<<"The task is completed first is employee:"<<temp->ID;
            return;
        }

    }

}
int main(){
    Node *head=NULL;
    insertend(&head,3,"001","AAA");
    insertend(&head,4,"002","BBB");
    insertend(&head,2,"003","CCC");
    task(head);

}

