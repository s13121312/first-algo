#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    int a[100005];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[100005];
    int c[100005]={0,};
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i]==a[j])
            {
                c[i]=1;
            }
        }
    }


    for(int i=0;i<m;i++)
    {
        cout << c[i] << '\n';
    }
    return 0;
}