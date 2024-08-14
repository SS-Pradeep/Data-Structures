#include<map>
#include<vector>
#include<iostream>
using namespace std;
int main(){

    map<char,int> m1;

    string s="ttttaae";

    vector<pair<char,int>> v1;


    int col=1;

    int rows=m1.size();


    for(char c:s){
        auto it=m1.find(c);
        if(it!=m1.end()){
            m1[c]+=1;
        }
        else{
            m1[c]=1;
        }
    }
    for(auto pair:m1){
        v1.push_back(pair);
    }

    sort(v1.begin(),v1.end(),[]const pair<char,int>&a,const<pair<char, int>&b){
        return a.second < b.second;
    }


    for(auto it=m1.begin();it!=m1.end();it++){
        cout<<it->first;
    }

    for(auto x:m1){
        cout<<x.second;
    }
}
