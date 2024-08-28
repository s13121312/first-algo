#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[15005];


void input(){

    cin >> n;
    cin >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
}

void pro(){
    sort(arr+1, arr+n+1);

    int r = n, ans = 0;
    int l = 1;

    while(l<r){
        if(arr[l] + arr[r] > m){
            r--;
        }else if(arr[l] + arr[r] < m){
            l++;
        }else{
            //cout << arr[l] <<' ' << arr[r] <<'\n';
            ans++;
            r--;
        }
    }
    
    cout << ans;
    
}

int main(){

    input();
    pro();

    return 0;
}