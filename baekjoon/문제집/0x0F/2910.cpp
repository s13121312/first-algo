#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    vector<pair<int, int>> v; // 빈도,값
    // 빈도 큰거부터 빈도만큼반복하고 stable_Sort사용해서 출력

    cin >> n >> c; // n개,c보다 작거나같은원소들

    // 존재하는지를 따로 또 판별해야하는가?
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        bool chk = false; // 원래 있던놈인지 체크
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].second == a)
            {
                chk = true;
                v[j].first++;
                break;
            }
        }
        if (!chk)
        {
            v.push_back({1, a});
        }
    }

    stable_sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
    {
        for(int j=0;j<v[i].first;j++){
            cout << v[i].second<<' ';
        }
    }

    return 0;
}