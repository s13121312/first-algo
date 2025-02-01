#include <bits/stdc++.h>
using namespace std;

int n;
int arr[13];
int giho[5]; // + - * / 개수

int max_sum = -999999999;
int min_sum = 999999999;
void func(int depth, int hap)
{

    if (depth == n)
    {
        if (hap > max_sum)
        {
            max_sum = hap;
        }
        if (hap < min_sum)
        {
            min_sum = hap;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (giho[i] == 0)
            continue;
        giho[i]--;
        if (i == 0)
        {
            func(depth + 1, hap + arr[depth]);
        }
        if (i == 1)
        {
            func(depth + 1, hap - arr[depth]);
        }
        if (i == 2)
        {
            func(depth + 1, hap * arr[depth]);
        }
        if (i == 3)
        {
            func(depth + 1, hap / arr[depth]);
        }
        giho[i]++;
    }
}

int main(void)
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> giho[i];
    }
    func(1, arr[0]); // 첫번째 arr[0]를 함수인자로 줌 아예

    cout << max_sum << '\n'
         << min_sum;
    return 0;
}