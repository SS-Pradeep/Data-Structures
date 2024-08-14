#include<iostream>
using namespace std;
int main(){
    int max2=0,min2=0;
    int a[]={91,4,95,1,87,90};
    int max1=a[0];
    int min1=a[0];
    for(int i=1;i<6;i++){
        if(a[i]>max1){
            max2=max1;
            max1=a[i];
        }
        else if(max2<a[i] && max1!=max2){
            max2=a[i];
        }
    }
    cout<<max2;
    for(int i=1;i<6;i++){
        if(a[i]<min1){
            min2=min1;
            min1=a[i];
        }
        else if(min2>a[i]){
            min2=a[i];
        }
    }
    cout<<" "<<min2;
}
