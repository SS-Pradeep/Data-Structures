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
    Node *temp=head;
    Node *New=new Node();


    while(temp!=NULL){

    New=temp->prev;
        temp->prev=temp->next;
        temp->next=New;
        temp=temp->prev;
        }
    if(New!=NULL){
        head=New->prev;
    }
    Node *prev=head;
     while(prev!=NULL){
        string s1=prev->data;
        reverse(s1.begin(),s1.end());
        prev->data=s1;
        prev=prev->next;
    }





   return head;
}


int main(){
    Node *head=new Node();
    Node *second=new Node();
    Node *third=new Node();

    head->data="Apple";
    head->next=second;
    head->prev=NULL;

    second->next=third;
    second->prev=head;
    second->data="banana";

    third->data="orange";
    third->prev=second;

    Node *result=rearrange(head);

    while(result!=NULL){
        cout<<result->data<<" ";
        result=result->next;
    }


}
