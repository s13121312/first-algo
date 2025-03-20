#include<bits/stdc++.h>
using namespace std;


int main(void){

    int arr[10]={0,9,4,3,7,2,1,6,5,8};
    for(int i=9;i>=1;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])swap(arr[j],arr[j+1]);
        }
    }
    for(int i=0;i<10;i++)
    {
        cout << arr[i];
    }
    

    return 0;
}