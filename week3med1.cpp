

#include<iostream>
using namespace std;
class Node{
    public:
    int data=0;
    Node *next=NULL;
};

Node *rearrange(Node *head){
   Node *prev = head;
Node *curr = head;

while (curr != NULL && curr->next != NULL) {
    if (prev->data != curr->next->data) {
        prev = prev->next;
        curr = curr->next;
    } else {
        curr->next = curr->next->next;
    }
}

return head;

}

int main(){
    Node *head=new Node();
    Node *second=new Node();
    Node *third=new Node();

    head->data=1;
    head->next=second;

    second->next=third;
    second->data=3;

    third->data=3;

    Node *result=rearrange(head);

    while(result!=NULL){
        cout<<result->data<<" ";
        result=result->next;
    }


}
