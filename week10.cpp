#include<iostream>
using namespace std;
class Node
{
public:

    int data;
    Node *right;
    Node *left;

    Node()
    {
        data=0;
        right=NULL;
        left=NULL;
    }
};

void insert1(Node **root,int data)
{
    Node *temp=new Node();
    temp->data=data;
    Node *new1=*root;
    if(root==NULL)
    {
        *root=temp;

    }
    else
    {
        if(new1->data < data){

        }
    }
}
int main()
{
    Node* root;
    root=NULL;
    insert1(&root,10);
}
