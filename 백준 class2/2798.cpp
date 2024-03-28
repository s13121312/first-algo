#include<bits/stdc++.h>
using namespace std;


int main(void)
{
    int n,m;
    cin >> n >>m;
    int sum=0;
    int arr[105];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                if(arr[i]+arr[j]+arr[k]<=m)
                {
                    sum = max(sum,arr[i]+arr[j]+arr[k]);
                }
            }
        }
    }

    cout << sum;
    return 0;
}