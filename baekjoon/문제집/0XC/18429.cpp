#include <bits/stdc++.h>
using namespace std;

int n, k;
int kit[10];

int order[10];
bool isused[10];
int ans = 0;

void func(int depth, int weight)
{
    if (depth == n - 1)
    {
        bool check = true;
        if (weight < 500)
        {
            return;
        }
        else
        {
            ans++;
            return;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!isused[i] && weight - k + kit[i] >=500)
        {
            isused[i] = true;
            func(depth + 1, weight - k + kit[i]);
            isused[i] = false;
        }
    }
}

int main(void)
{

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {

        cin >> kit[i];
    }

    func(0, 500);
    cout << ans;
    return 0;
}