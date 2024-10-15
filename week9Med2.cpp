#include<iostream>
using namespace std;
class Node{
public:

    Node *next=NULL;
    int stock=0;
};
void insertend(Node **head,int stock){
    Node *newnode=new Node();
    newnode->stock=stock;
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
        if(temp1->stock < temp2->stock){

            insertend(&newnode25,temp1->stock);
            temp1=temp1->next;

        }
        else{

            insertend(&newnode25,temp2->stock);
            temp2=temp2->next;

        }
    }while(temp1!=head1 && temp2!=head2);

    if(temp2==head2){
        insertend(&newnode25,temp2->stock);
        temp2=temp2->next;
    }

    do{
        insertend(&newnode25, temp1->stock);
        temp1 = temp1->next;
    }while(temp1!=head1);
    do{
        insertend(&newnode25, temp2->stock);
        temp2 = temp2->next;
    }while(temp2!=head2);



}

void print(Node *head){
    Node *new1=head;
    do{
        cout<<new1->stock<<"->";
        new1=new1->next;
    }while(new1!=head);
}

void split(Node* source, Node** front, Node** back) {
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    // Move fast two nodes and slow one node
    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Slow is before the midpoint, split it in two
    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

Node* merge(Node* front, Node* back) {
    if (front == nullptr) return back;
    if (back == nullptr) return front;

    // Start with the linked list that has the smaller stock
    if (front->stock <= back->stock) {
        front->next = merge(front->next, back);
        return front;
    } else {
        back->next = merge(front, back->next);
        return back;
    }
}

Node* mergeSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head; // Base case: if the list is empty or has one element
    }

    Node* front;
    Node* back;

    // Split the list into two halves
    split(head, &front, &back);

    // Recursively sort the sublists
    front = mergeSort(front);
    back = mergeSort(back);

    // Merge the sorted sublists
    return merge(front, back);
}
int main(){
    Node *head=NULL;

     insertend(&head,1);
    insertend(&head,5);
    insertend(&head,4);
    insertend(&head,6);

    cout << "Original Product List:" << endl;
    print(head);

    head = mergeSort(head);

    cout << "\nSorted Product List (by Stock):" << endl;
    print(head);


}

