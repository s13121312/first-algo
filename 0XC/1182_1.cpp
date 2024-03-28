#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int n, s;
int sum[25];

int arr[25];

void func(int depth, int hap) // 현재까지의 합
{
    if (depth == n)
    {
        if (hap == s)
        {
            ans++;
            
        }
        return;
    }

    func(depth + 1, hap);
    func(depth + 1, hap + arr[depth]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    func(0, 0);

    if (s == 0)
        ans = ans - 1; // 공집합
    cout << ans;
    return 0;
}