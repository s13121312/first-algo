#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int arr[10];
    for(int i=0;i<n;i++)
    {
        cin >>arr[i];
    }
    int sum=0;
    int max=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                sum = arr[i]+arr[j]+arr[k];
                if(sum>m)continue;
                if(max<sum)
                {
                    max=sum;
                }
            }
        }
    }
    cout << max;
    return 0;
}