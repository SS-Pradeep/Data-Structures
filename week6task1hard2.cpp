#include<iostream>
using namespace std;

class Node{
public:
    char data;
    Node *next=NULL;

    Node(){
        data=0;
        next=NULL;
    }

    Node(char c){
        this->data=c;
    }
};
class stack1{
    Node *top=NULL;
public:

void push(char data){
    Node *temp=new Node(data);
    if(!temp){
        cout<<"Error";
    }
    else{
        temp->data=data;
        temp->next=top;
        top=temp;
    }

}

void pop(){
    Node *temp=top;
    top=top->next;
    delete temp;
}
bool isempty(){
    return top==NULL;
}

char peek(){
    if(!isempty()){
        return top->data;
    }
    else{
        exit(1);
    }
}
void display(){
    Node *temp=NULL;
    temp=top;
    if (isempty()) {
            cout << "Stack is empty" << endl;
            return;
        }
    cout<<endl;

    while(temp!=NULL){
        cout<<temp->data;
        temp=temp->next;
    }
}
};

stack1 problem(stack1 s1,char c){

    stack1 s2;
    char a=s1.peek();

    stack1 result;
    while(!s1.isempty()){
        if(s1.peek()==c){

            result.push(c);
        }
        else{


            s2.push(s1.peek());
        }
        s1.pop();
    }
    while(!s2.isempty())
    {
        s1.push(s2.peek());
        s2.pop();
    }
    while(!result.isempty()){
        s1.push(result.peek());
        result.pop();
    }
    return s1;

}
int main()
{
    stack1 s1;
    char c;
    char ch;
    cout<<endl;
    cout<<"Enter the elements Press('/') to stop:"<<endl;
    while(true){
        cin>>ch;
        if(ch=='/'){
            break;
        }
        s1.push(ch);
    }
    s1.display();
    cout<<endl;
    cout<<"Enter a element for search:(Press '/' to exit):"<<endl;

    cout<<endl;

    cin>>c;
    stack1 result=problem(s1,c);
    result.display();
}
