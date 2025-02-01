//시간복잡도 n^2
//시간복잡도 n인 풀이생각해야함

#include <bits/stdc++.h>
using namespace std;

int n;
int visit[100003];

// void run(int idx){

// }

bool iscycle(int idx)
{
    int cur = idx;
    for(int i=0;i<n;i++)
    {
        cur = visit[cur];
        if(cur == idx)
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> visit[i];
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!iscycle(i))
            {
                ans++;
            }
        }
        cout <<ans << '\n';
    }

    return 0;
}