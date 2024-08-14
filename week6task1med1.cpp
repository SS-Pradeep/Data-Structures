#include<algorithm>
#include<string>
#include<stack>
#include<iostream>
using namespace std;

stack<int> problem(stack<int> s1,stack<int> s2)
{
    stack<int> s3;

    while(!s1.empty() && !s2.empty())
    {

        if(s1.top() > s2.top()){
            s3.push(s1.top());
            s1.pop();
        }
        else{
            s3.push(s2.top());
            s2.pop();
        }
    }
    while(!s2.empty()){
        s3.push(s2.top());
        s2.pop();
    }
    while(!s1.empty()){
        s3.push(s1.top());
        s1.pop();
    }
    return s3;
}

void display(stack<int> sq){
    while(!sq.empty()){
        cout<<sq.top()<<" ";
        sq.pop();
    }
    cout<<endl;

}
int main(){
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    int c=0;
    cout<<"Enter elements in stack1:(Press -1 to stop)"<<endl;
    while(true){
        cin>>c;
        if(c==-1)
            break;
        s1.push(c);
    }
    cout<<endl;
    cout<<"Enter elements in stack2:(Press -1 to stop)"<<endl;
    while(true){
        cin>>c;
        if(c==-1)
            break;
        s2.push(c);
    }
    cout<<"Displaying 1 stack:"<<endl;
    display(s1);
    cout<<"Displaying 2nd stack:"<<endl;
    display(s2);
    s3=problem(s1,s2);
    cout<<"Displaying merge stack:"<<endl;
    display(s3);
}
