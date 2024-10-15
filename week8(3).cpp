#include<vector>
#include<iostream>
using namespace std;
int main(){
    vector<int> v1={1,2,9,8,7,6,5,4};

    for(int i=1;i<v1.size();i++){
            int temp=v1[i];
            int j=i-1;
            while(j>=0 && v1[j]>temp){
                swap(v1[j+1],v1[j]);
                j--;
            }


    }
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }

    return 0;
}
