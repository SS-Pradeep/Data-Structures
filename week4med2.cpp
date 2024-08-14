#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class life{
    public:
    char st[1000];
    int top;
    life(){
        top=-1;
    }
    void push(int a){
        if(top>=1000-1){
            cout<<"Stack overflow";
        }
        else{
            st[++top]=a;

        }

    }
    bool isempty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }}
    int pop(){
      if(top<0){
        return -1;
      }
      else{
        int a=st[top];
        top--;
        return a;
      }
    }
};
void display(life s1){
    int a=s1.top;
    while(a!=-1){
        cout<<s1.st[a];
        a--;
    }
}
string problem(life s1)
{
    int a=s1.top;
    string s="";
    string result="";
    while(a!=-1){
        int b=s1.st[a]-'0';
        if(s1.st[a-1]=='['){
            while(s1.st[a-2]!=']'){
            s=s+s1.st[a-2];
            a--;}
            a-=3;
        }
    for(int i=0;i<b;i++){
        result=result+s;
    }
    s="";

        }
    return result;
}
int main(){
    life s1;
    string s;
    cout<<"Enter the string:";
    cin>>s;
    reverse(s.begin(),s.end());
    for(char c:s){
        s1.push(c);
    }

    string s2=problem(s1);
    cout<<s2;
}
