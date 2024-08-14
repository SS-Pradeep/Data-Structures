#include<algorithm>
#include<iostream>
using namespace std;
struct movie{
    string name;
    float rating;
};
void mergesortfull(struct movie arr[],int left,int middle,int right){
    int n1=middle-left+1;
    int n2=right-middle;
    struct movie l[n1],r[n2];
    for(int i=0;i<n1;i++){
        l[i]=arr[left+i];
    }
    for(int i=0;i<n2;i++){
        r[i]=arr[i+1+middle];
    }
    int k=left,i=0,j=0;
    while(i<n1 && j<n2){
        if(l[i].rating<=r[j].rating){
            arr[k]=l[i];
            i++;
        }
        else {
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=l[i];
        k++;
        i++;
    }
    while(j<n2){
        arr[k]=r[j];
        k++;
        j++;
    }

}
void mergesort(struct movie arr[],int left,int right){
    if(left < right){
        int middle=(left+right)/2;
        mergesort(arr,left,middle);
        mergesort(arr,middle+1,right);
        mergesortfull(arr,left,middle,right);
    }
}
void printarray(struct movie sorted[],int n){
    for(int i=0;i<n;i++){
        cout<<sorted[i].name<<endl;
        cout<<sorted[i].rating<<endl;}
}

int main(){
    int n;
    cout<<"Enter the no of movies:";
    cin>>n;
    struct movie mno[n];
    for(int i=0;i<n;i++){
        cout<<"enter name of movie:";
        cin>>mno[i].name;
        cout<<"enter rating for the movie:";
        cin>>mno[i].rating;
    }
    mergesort(mno,0,n-1);
    cout<<"After sorting"<<endl;
    printarray(mno,n);
}
