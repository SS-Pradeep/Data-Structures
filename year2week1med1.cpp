#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int max2=0,min2=0,num=0;
    vector<int> a;
    cout<<"Enter input:";
    while(true){
        cin>>num;
        if(num == -1)
            break;
        a.push_back(num);
    }
    int max1=a[0];
    int min1=a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]>max1){
            max2=max1;
            max1=a[i];
        }
        else if(max2<a[i] && max1!=max2){
            max2=a[i];
        }
    }
    cout<<"Max:"<<max2<<endl;
    int n=a.size();
    sort(a.begin(),a.end());
    cout<<"Min:"<<a[2];
}
