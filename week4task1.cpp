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
life problem(life st){
    int b=0;
    int a=st.top;
    while(a!=-1){
    if(st.st[a]=='*'){
        if(st.st[a+1]!='/'){
            st.st[a+1]='/';
            st.st[a]='/';
            a--;
        }
        else{
                st.st[a]='/';
                b=a+1;
        while(st.st[b]=='/'){
            b++;
        }
        st.st[b]='/';
        a--;
        }
    }
    else{
        a--;
    }}
    return st;}
string constr(life s2){
    string strin="";
    int a=s2.top;
    while(a!=-1){
        if(s2.st[a]!='/'){
            strin+=s2.st[a];
        }
        a--;
    }
    return strin;
}
int main(){
    life s1;
    s1.top=-1;
    string s;

    cout<<"Enter the string:";
    cin>>s;
    reverse(s.begin(),s.end());

    for(char c:s){
        s1.push(c);
    }

    life s2=problem(s1);
    //display(s1);
    display(s2);
    string result=constr(s2);
    cout<<endl<<result;





    }
