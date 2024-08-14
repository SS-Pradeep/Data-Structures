#include<iostream>
using namespace std;
struct class1{
    int grade;
    string name;
};
int main(){
    int n,min1;
    cout<<"Enter how many elements:";
    cin>>n;
    struct class1 student[n];
    for(int i=0;i<n;i++){
            cout<<"enter student name:";
        cin>>student[i].name;
    cout<<"Enter student grade:";
        cin>>student[i].grade;
    }
    for(int i=0;i<n-1;i++){
        min1=i;
        for(int j=i+1;j<n;j++){
            if(student[j].grade<student[min1].grade){
                min1=j;
            }

        }
        swap(student[i],student[min1]);

    }
    for(int i=0;i<n;i++){
        cout<<student[i].grade<<" ";;
    }
}
