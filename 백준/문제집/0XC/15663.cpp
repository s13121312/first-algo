#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

int num[10];
bool visit[10];

int main(void)
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    func(0);

    return 0;
}

void func(int depth)
{

    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << num[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        // 이전수열의 마지막 항과 새로운 수열 마지막 항이 같은 경우
        if (!visit[i] && num[i] != tmp) // 79  79를 보면
        {
            num[depth] = arr[i];
            visit[i] = true;
            tmp = num[depth]; //!!!

            // 중복 제거 작업
            func(depth + 1);
            visit[i] = false;
        }
    }
}