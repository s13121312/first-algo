#include <bits/stdc++.h>
using namespace std;
int n, s;
int arr[100005];

void input()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void pro()
{

    int l = 0;
    int ans = 0x7fffffff;
    int tmp = 0;
    int r=0;
    for (r = 0; r < n; r++)
    {
        tmp += arr[r];

        while (tmp >= s)
        {
            ans = min(ans, r - l + 1);
            tmp -= arr[l++];  
            
        }
        //cout << '\n' << l << ' ' << r;
        
    }
    if(ans == 0x7fffffff)cout << 0;
    else cout << ans;

    
}

int main()
{

    input();
    pro();

    return 0;
}