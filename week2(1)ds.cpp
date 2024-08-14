#include<iostream>
using namespace std;
struct employee{
    int salary;
    string name;
};

int main(){
    int n,min1;
    cout<<"Enter how many elements:";
    cin>>n;
    struct employee emp[n];
    for(int i=0;i<n;i++){
            cout<<"enter emp name:";
        cin>>emp[i].name;
    cout<<"Enter emp salary:";
        cin>>emp[i].salary;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(emp[j].salary>emp[j+1].salary){
                swap(emp[j],emp[j+1]);
            }
        }
    }
        for(int i=0;i<n;i++){
        cout<<emp[i].salary<<" ";
    }
}
