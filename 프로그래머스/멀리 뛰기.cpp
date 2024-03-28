#include <bits/stdc++.h>
using namespace std;

long long d[2005];
const int k = 1234567;
long long solution(int n)
{
    long long answer = 0;

    d[1] = 1;
    d[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        d[i] = d[i - 1] % k + d[i - 2] % k;
        d[i] = d[i] % k;
    }

    answer = d[n];
    return answer;
}