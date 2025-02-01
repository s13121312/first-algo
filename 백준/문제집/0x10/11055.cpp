// 다시풀기
#include <bits/stdc++.h>
using namespace std;

int a[1005];
int dp[1005]; // i번째까지 최대 합 (증가하는 부분수열의합)
int main(void)
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i]=a[i];
    }

    
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<i;j++){
            if(a[j]<a[i]) dp[i]=max(dp[i],dp[j]+a[i]); //dp[i]단독이 클수도있으니까~
        }
    }

    cout << *max_element(dp,dp+n);

    return 0;
}