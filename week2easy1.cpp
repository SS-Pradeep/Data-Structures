/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Node{
    public:
    string data;
    int id,salary;
    Node *next=NULL;
};

Node *rearrange(Node *head){
    Node *current=head;
    Node *result=NULL;
    vector<int> v1;
    while(current != NULL){
        v1.push_back(current->salary);
        current=current->next;
    }
    int posi=1;
    int maxi=v1[0];
    for(size_t i=1;i<v1.size();i++){
        if(v1[i] > maxi){
            maxi=v1[i];
            posi=i+1;
        }
    }
    Node *temp=head;int j=1;
    while(temp!=NULL){
            if(j==posi){
                result=temp;
                result->next=NULL;
            }
            j++;
            temp=temp->next;

    }


   return result;
}

int main(){
    Node *head=new Node();
    Node *second=new Node();
    Node *third=new Node();

    head->data="Pradeep";
    head->id=1;
    head->salary=100000;
    head->next=second;

    second->next=third;
    second->id=2;
    second->salary=20000;
    second->data="Madhan";

    third->id=1;
    third->salary=20000;
    third->data="Thayu";

    Node *result=rearrange(head);

    while(result!=NULL){
        cout<<"The person with highest salary is:"<<result->data<<" ";
        result=result->next;
    }


}
