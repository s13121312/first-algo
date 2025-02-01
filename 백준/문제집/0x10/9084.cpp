// #include<bits/stdc++.h>
// using namespace std;

// int dongjun(int *arr, int n, int m){
//     int d[10005];

//     d[0]=1;
//     for(int i=1;i<=n;i++){
//         for(int j=arr[i];j<=m;j++){
//             d[j] = d[j] + d[j-arr[i]];
//         }
//     }
//     return d[m];
// }
// int main(void){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int a[25];
//         int n, m;
//         cin >> n;
//         for(int i=1;i<=n;i++){
//             cin >> a[i];
//         }
//         cin >> m;
//         cout << dongjun(a,n,m) << '\n';
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int d[10005];
int a[25];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, m;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        cin >> m;
        fill(d,d+m+1,0);
        d[0]=1;
        for(int j=0;j<n;j++){
            for(int k=a[j];k<=m;k++){
                d[k] += d[k-a[j]];
            }
        }
        cout << d[m]<<'\n';
    }

    return 0;
}