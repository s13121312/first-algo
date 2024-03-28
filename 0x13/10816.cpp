#include<bits/stdc++.h>
using namespace std;

int a[500005];


int lower(int target,int len){
    int st = 0;
    int en =len;
    while (st<en)
    {
        int mid = (st+en)/2;
        if(a[mid]<target){
            st = mid +1;
        }
        if(a[mid]>=target){
            en = mid;
        }
    }
    return st;
    
}

int upper(int target,int len){
    int st = 0;
    int en =len;
    while (st<en)
    {
        int mid = (st+en)/2;
        if(a[mid]>target){
            en = mid;
        }
        if(a[mid]<=target){
            st = mid + 1;
        }
    }
    return en;
    
}
int main(void){

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);

    int m;
    cin >> m;

    while (m--)
    {
        int k;
        cin >> k;
        cout << upper(k,n)-lower(k,n)<< ' ';
    }
    


    return 0;
}