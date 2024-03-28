#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[100005];

int len = 0x7fffffff;

int main(void)
{

    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    int en = 0;
    int sum = arr[0];

    for (int st = 0; st < n; st++)
    {
        while (en < n && sum < s)
        {
            en++;
            if (en != n) sum += arr[en];
        }
        if (en == n)
            break;
        len = min(len, en - st + 1);
        sum -= arr[st];
    }
    if (len == 0x7fffffff)
    {
        len = 0;
    }
    cout << len;

    return 0;
}