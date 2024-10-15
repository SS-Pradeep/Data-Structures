#include<vector>
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data=0;
        left=right=NULL;
    }
    Node(int key)
    {
        this->data=key;
        left=right=NULL;
    }
};
vector<int> v1;
void insertback(Node **root,int data)
{
    Node *temp=*root;
    if(*root == NULL)
    {
        *root = new Node(data);
        return;

    }
    if(data < temp->data)
    {
        insertback(&(temp->left),data);
    }
    else
    {
        insertback(&(temp->right) ,data);
    }
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data;
}
void preorder(Node *root)
{
   if (root == NULL)
    {
        return;
    }
    v1.push_back(root->data);
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    Node *root= new Node();
    root=NULL;
    int c=0;
    while(true)
    {
        cout<<"Enter the element:";
        cin>>c;
        if(c==-1)
            break;
        insertback(&root,c);
    }
    postorder(root);
    cout<<endl;
    preorder(root);
    for(int i:v1)
    {
        cout<<i<<endl;
    }
    int n=v1.size();
    for(int i=0;i<n/2;i++)
    {
        int temp=v1[i];
        v1[i]=v1[n-i-1];
        v1[n-i-1]=temp;
    }
    for(int i:v1)
    {
        cout<<i<<" ";
    }
}
