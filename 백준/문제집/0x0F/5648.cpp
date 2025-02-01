#include <bits/stdc++.h>
using namespace std;

long long arr[1000005];
int n;

int main(void)
{

    cin >> n;
    int l;
    long long r; // 뒤집은거
    for (int i = 0; i < n; i++)
    {
        r=0;
        long long a;
        cin >> a;
        while (a)
        {
            r=(r*10)+(a%10);
            a/=10;
        }
        
        arr[i] = r;
    }

    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        cout << arr[i]<<'\n';
    }

    return 0;
}