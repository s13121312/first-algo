//다시 풀기
#include <bits/stdc++.h>
using namespace std;

int t[20];
int p[20];
int d[30]; // i번째 일에 상담을 시작했을 때 얻을 수 있는 최대 수익

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }

    for (int i = n; i >= 1; i--)
    {
        //i번째날에 일을 할때 안하거나 한거 중 큰거 (왜 안한거를 비교하냐? -> t를 고려해야하기때문에 건너뛰어서 더 좋은값이 나올수있음 )
        if (i + t[i] <= n + 1)
        {
            d[i] = max(d[i + t[i]] + p[i], d[i+1]);
        }
        //i번째 
        else{
            d[i]=d[i+1];
        }
    }
    cout << *max_element(d+1,d+n+1);
    return 0;
}