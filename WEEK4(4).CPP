#include<iostream>
using namespace std;
class Node{
public:

    Node *next=NULL;
    int priority=0;
    string name;
    int id;
};
void addtask(Node **head,int priority,string name,int id){
    Node *newnode=new Node();
    newnode->priority=priority;
    newnode->id=id;
    newnode->name=name;
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
void print(Node *head){
    if(head==NULL){
        return;
    }
    Node *new1=head;
    do{
        cout<<"ID:"<<new1->id<<" "<<"Name:"<<new1->name<<" "<<"Priority:"<<new1->priority<<endl;
        new1=new1->next;
    }while(new1!=head);
}
void removetask(Node **head,int id){
     if(*head==NULL){
            return;
    }


    Node *curr=*head;
    Node *result=nullptr;
    Node *currnext=nullptr;
    if(curr->id==id){
        result=curr;
        currnext=curr->next;
        while(curr->next!=*head){
            curr=curr->next;
        }
        curr->next=currnext;
        delete result;
        *head=curr;
        return;

    }
    do{
        if(curr->next->id==id){
            result=curr->next;
            break;
        }
        curr=curr->next;
        }while(curr!=*head);
        curr->next=result->next;
        delete result;
        cout<<endl<<"The task was executed successfully"<<endl;

}
void execute(Node **head){
    if(*head==NULL){
            return;
    }
    int maximum=0;
    Node *curr=*head;
    Node *real=nullptr;
    do{
        if(curr->priority > maximum){
            maximum=curr->priority;
            real=curr;
        }
        curr=curr->next;
    }while(curr!=*head);

    if(real!=nullptr){
            cout<<endl;
        cout<<"The task was exected according to priority was:"<<endl;
        cout<<"ID:"<<real->id<<endl;
        cout<<"Name:"<<real->name<<endl;
        cout<<"Priority:"<<real->priority<<endl;
        removetask(head,real->id);
    }
}

int main(){
    Node *head=NULL;
    addtask(&head,5,"Task 01",1);
    addtask(&head,4,"Task 02",2);
    addtask(&head,3,"Task 03",3);
    addtask(&head,7,"Task 04",4);
    print(head);
    execute(&head);
    print(head);
    execute(&head);
    print(head);
    execute(&head);
    print(head);
    execute(&head);
    print(head);
    execute(&head);

}
