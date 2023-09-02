#include <bits/stdc++.h>
using namespace std;
/*
int main(void)
{
    int n, arr[100000],x,cnt=0;
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]+arr[j]==x)
            {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}*/
int main(void)
{
    
    cin.tie(0);
    int n, arr[100001],x,cnt=0;
    int occur[200000];
    cin >>n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    for(int i=0;i<n;i++)
    {
        if(x-arr[i]>0 && occur[x-arr[i]]==1)
        {
            cnt++;
        }
        occur[arr[i]]=1;
    }
    cout << cnt;
    return 0;
}