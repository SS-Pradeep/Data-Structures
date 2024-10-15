#include<iostream>
using namespace std;
class Employees{
public:
    string name;
    int age,salary;
    Employees(){
        name="";
        age=0;
        salary=0;
    }
    void set1(string name,int age,int salary)
    {
        this->name=name;
        this->age=age;
        this->salary=salary;
    }

};
int partition1(Employees arr[],int low,int high)
{
    int pivot=arr[high].age;
    int i = low - 1;

    for(int j=low;j<high;j++)
    {
        if(arr[j].age < pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(Employees arr[],int low,int high)
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
    cout<<"Enter no of Employees:";
    cin>>n;
    Employees* employee = new Employees[n];
    for(int i=0;i<n;i++)
    {
        string name;
        int age,salary;
        cout<<"Enter name of "<<i+1<<"th Employee:";
        cin>>name;
        cout<<"Enter age of "<<i+1<<"th Employee:";
        cin>>age;
        cout<<"Enter salary of "<<i+1<<"th Employee:";
        cin>>salary;
        employee[i].set1(name,age,salary);

    }
    quicksort(employee,0,n-1);
    cout<<"After sorting:"<<endl;
    for(int i=0;i<n;i++)
    {

        cout<<"Name of "<<i+1<<"th Employee:"<<employee[i].name<<endl;
        cout<<"Age of "<<i+1<<"th Employee:"<<employee[i].age<<endl;
        cout<<"Salary of "<<i+1<<"th Employee:"<<employee[i].salary<<endl;


    }






}
