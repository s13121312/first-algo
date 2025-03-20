#include <bits/stdc++.h>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int arr[10]={}, ans = 0;
    while(N>0)
    {
        arr[N%10]++;
        N /=10;
    }
    
    for(int i=0;i<10;i++)
    {
        if(i==6 || i==9)
        {
            continue;
        }
        ans = max(ans,arr[i]);
    }
    
    ans = max(ans,(arr[6]+arr[9]+1)/2);
    
    cout << ans;
    return 0;
    
}