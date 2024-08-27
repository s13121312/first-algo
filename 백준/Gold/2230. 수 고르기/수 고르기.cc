#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[100005];

void input(){

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    
}

void pro(){

    sort(arr, arr+n);

    int r =0, ans =0x7fffffff;
    
    for(int l=0;l<=n-1;l++){

        while (r+1 < n && arr[r]- arr[l] < m)
        { 
            ++r;
        }
        if(arr[r]- arr[l] >= m){
            ans = min(ans, arr[r]- arr[l]);
        }
    }
    

    cout << ans;
}

int main(){

    input();
    pro();

    return 0;
}