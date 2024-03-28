#include <bits/stdc++.h>
using namespace std;

long long arr[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    arr[n]=(1ll << 62)+1;
    
    int cnt=1;
    int max_cnt=0;
    int max_value;
    for(int i=1;i<=n;i++){
        if(arr[i-1]==arr[i])cnt++;
        else{
            if(cnt>max_cnt){
                max_cnt=cnt;
                max_value=arr[i-1];
            }
            cnt=1;
        }
    }
    
    cout<<max_value;
}