#include<iostream>
using namespace std;


int partition1(int arr[],int low,int high)
{
    int pivot=arr[high];
    int i = low - 1;

    for(int j=low;j<high;j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(int arr[],int low,int high)
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
    int arr[10]={5,6,4,7,3,8,9,2,0,0};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr , 0, n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

}
