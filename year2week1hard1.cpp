#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int a[]={2,3,6,7,8,9,10,19};
    int b=0,c[10]={0},j=0;
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=1;i<n;i++){
        if(a[i]-1==a[i-1]){
            b+=1;
        }
        else if(a[i]-1!=a[i-1]){
                c[j]=b;
                b=0;
                j++;
        }
    }
    int n1=sizeof(c)/sizeof(c[0]);
    int max1=c[0];
    for(int i=0;i<n1;i++){
            if(c[i] > max1){
                max1=c[i];
            }
    }
    cout<<"Length of longest sub array is:"<<max1+1;

}
