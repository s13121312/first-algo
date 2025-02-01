#include <bits/stdc++.h>
using namespace std;

int d[1005][3];

int r[1005];
int g[1005];
int b[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> r[i] >> g[i] >> b[i];
    }

    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];
    int ans = 1001;
    for (int i = 2; i <= n; i++)
    {
        d[i][0] = r[i] + min(d[i - 1][1], d[i - 1][2]);
        d[i][1] = g[i] + min(d[i - 1][0], d[i - 1][2]);
        d[i][2] = b[i] + min(d[i - 1][0], d[i - 1][1]);
    }
    ans = min(d[n][0], d[n][1]);
    ans = min(ans, d[n][2]);

    cout << *min_element(d[n], d[n] + 3);
    return 0;
}