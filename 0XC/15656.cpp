#include <bits/stdc++.h>
using namespace std;

int n, m; // 1<=n,m<=7
int input[10];
int arr[10];

void func(int depth,int st)
{

    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0;i<n;i++)
    {
        arr[st]=input[i];
        func(depth+1,st+1);
    }
}

int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    sort(input, input + n);

    func(0,0);

    return 0;
}