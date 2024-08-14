#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int a[]={1,0,2,3,4,4,5,5};
    int b=0;
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]-1==a[i-1]){
            b+=1;
        }
    }
    cout<<b;

}
