#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
class Node{
    public:
        Node *prev=NULL;
    string data;
    Node *next=NULL;
};

Node *rearrange(Node *head){
    Node *curr=head,*output=NULL;
    while(curr!=NULL){
        output->prev=curr->next;
        output->next=curr->prev;
        curr=curr->next;
        output=output->next;

    }



   return head;
}

int main(){
    Node *head=new Node();
    Node *second=new Node();
    Node *third=new Node();


    head->data="Apple";
    head->next=second;

    second->prev=head;
    second->next=third;
    second->data="banana";

    third->prev=second;
    third->data="orange";

    Node *result=rearrange(head);

    while(result!=NULL){
        cout<<result->data<<" ";
        result=result->next;
    }


}
