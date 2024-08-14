#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next=NULL;
};

Node *rearrange(Node *head1,Node *head2){
    Node *prev1=NULL;
    Node *curr1=head1,*Next1=NULL;
    while(curr1!=NULL){
        Next1=curr1->next;

        curr1->next=prev1;

        prev1=curr1;

        curr1=Next1;
    }
    head1=prev1;

    Node *prev2=NULL;
    Node *curr2=head2,*Next2=NULL;
    while(curr2!=NULL){
          Next2=curr2->next;

        curr2->next=prev2;

        prev2=curr2;

        curr2=Next2;
    }
    head2=prev2;
    Node *result=new Node(),*return1=result;
    int a=0,b=0;
    while(prev1!=NULL && prev2!=NULL){
        int sum=prev1->data+prev2->data;
        Node *New=new Node();
        if(sum >=10){
            a=sum/10;
            sum=sum%10;


        New->data=sum;}
        else{
            New->data=sum+a;
            a=0;
        }
        result->next=New;
        result=result->next;
        prev1=prev1->next;
        prev2=prev2->next;
    }
    while(prev1!=NULL){
            int sum=prev1->data+a;
        Node *New=new Node();

        New->data=sum;
        result->next=New;
        result=result->next;
        prev1=prev1->next;

    }
    while(prev2!=NULL){
        int sum=prev1->data+prev2->data;
        Node *New=new Node();

        New->data=sum;
        result->next=New;
        result=result->next;
        prev2=prev2->next;
    }
    return return1->next;


}

int main(){
    Node *head1=new Node();
    Node *second=new Node();
    Node *third=new Node();

    head1->data=1;
    head1->next=second;

    second->next=third;
    second->data=2;

    third->data=3;

    Node *head2=new Node();
    Node *second2=new Node();
    Node *third2=new Node();



    head2->data=1;
    head2->next=second2;

    second2->next=third2;
    second2->data=2;

    third2->data=9;

    Node *result=rearrange(head1,head2);

    Node *prev1=NULL;
    Node *curr1=result,*Next1=NULL;
    while(curr1!=NULL){
        Next1=curr1->next;

        curr1->next=prev1;

        prev1=curr1;

        curr1=Next1;
    }
    result=prev1;

    while(result!=NULL){
        cout<<result->data<<" ";
        result=result->next;
    }


}
