#include<iostream>
using namespace std;
class Student{
public:
    string name;
    int internalmarks,externalmark,finalmark;
    Student(){
        name="";
        internalmarks=0;
        externalmark=0;
        finalmark=0;
    }
    void set1(string name,int internalmarks,int externalmark)
    {
        this->name=name;
        this->internalmarks=internalmarks;
        this->externalmark = externalmark;
        this->finalmark = calculate();
    }

    int calculate()
    {
        return internalmarks+externalmark;
    }
    void display()
    {
        cout<<endl;
        cout<<name<<" "<<internalmarks<<" "<<externalmark<<" "<<finalmark;
    }
};


int partition1(Student arr[],int low,int high)
{
    int pivot=arr[high].finalmark;
    int i = low - 1;

    for(int j=low;j<high;j++)
    {
        if(arr[j].finalmark > pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(Student arr[],int low,int high)
{
    if(low < high)
    {
        int pi= partition1(arr ,low, high);
        quicksort(arr ,low,pi-1);
        quicksort(arr, pi+1, high);
    }
}
int main()
{
    int n;;
    cout<<"Enter no of Student:";
    cin>>n;
    Student* student = new Student[n];
    for(int i=0;i<n;i++)
    {
        string name;
        int internalmarks,externalmark;
        cout<<"Enter name of "<<i+1<<"th student:";
        cin>>name;
        cout<<"Enter internalmarks of "<<i+1<<"th student:";
        cin>>internalmarks;
        cout<<"Enter externalmark of "<<i+1<<"th student:";
        cin>>externalmark;
        student[i].set1(name,internalmarks,externalmark);

    }
    quicksort(student,0,n-1);
    cout<<"After sorting:"<<endl;
    for(int i=0;i<n;i++)
    {

        cout<<"Name of "<<i+1<<"th Student:"<<student[i].name<<endl;
        cout<<"internalmarks of "<<i+1<<"th Student:"<<student[i].internalmarks<<endl;
        cout<<"externalmark of "<<i+1<<"th Student:"<<student[i].externalmark<<endl;
        cout<<"FinalMark of "<<i+1<<"th Student:"<<student[i].finalmark<<endl;


    }






}
