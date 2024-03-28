#include<bits/stdc++.h>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int w[60];
    int h[60];
    int ans[60];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >>w[i] >> h[i];
    }
    
    for(int i=0;i<n;i++)
    {
        int k=1;
        for(int j=0;j<n;j++)
        {
            if(w[i]<w[j] && h[i]<h[j])
            {
                k++;
            }
            ans[i]=k;
        }
    }

    for(int i=0;i<n;i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}