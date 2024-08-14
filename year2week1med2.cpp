#include<iostream>
using namespace std;
int main(){
   int n=0;
    cout << "Enter size of array : ";
    cin >> n;
    cout << "Enter elements of array : ";
     int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int odd=0,even=0;

    int left=0;
    int right=n-1;
    while(left < right){
        int mid=(left+right)/2;
        for(int i=0;i<mid;i++){
                if(a[i]%2==0){
                    even+=1;
                }
                else{
                    odd+=1;
                }

        }
        left=mid+left;
    }
    cout<<"Odd:"<<odd<<endl<<"Even:"<<even;
}
