#include<algorithm>
#include<string>
#include<stack>
#include<iostream>
using namespace std;

int problem(string s)
{
    int j=0;
    int b=s.length();
    int a=s.length();
    stack<char> original;
    stack<char> dustbin;
    stack<char> restore;
    stack<char> regain;
    for(char c:s){
        original.push(c);
    }
    int i=0;
    while(!original.empty()){
        char c=original.top();
        restore.push(c);
        original.pop();
        while(!original.empty()){
                i=0;

            if(c==original.top()){
                dustbin.push(restore.top());
                dustbin.push(original.top());
                j+=2;
                original.pop();
                restore.pop();
                break;


            }
            else{
                regain.push(original.top());
                original.pop();
                i++;
            }

        }
        if(a==0){
                return b;
            }
        if(dustbin.empty()){

            return a;
        }
        if(!dustbin.empty()){
            a-=2;
        }

            while(j!=0){
            dustbin.pop();
            j--;}

        while(!regain.empty()){
            original.push(regain.top());
            regain.pop();
        }

    }
    return -1;

}

int main()
{
    string s="";
    cin>>s;
    reverse(s.begin(),s.end());
    int result=problem(s);

    int b=s.length();
    cout<<b-result-1;;
}
