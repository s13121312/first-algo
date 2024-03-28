//다시 풀기
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
vector<pair<int, int>> result(10);
int ans = 1e9;
int n;
bool isused[15];

void func(int idx, int depth)
{
    // 적어도 하나 사용
    // 조합을 해서 if절에서 처리하면되겠다
    // n개중에 몇개를 고름 (nCr)

    if (depth > 0)
    { // base condition 을 못잡겠다!~
        // 신맛 쓴맛 차이 계산
        int sin = result[0].first;
        int ssun = result[0].second;

        for (int i = 1; i < depth; i++)
        {
            sin *= v[i].first;
            ssun += v[i].second;
        }    
        ans = min(ans, abs(sin - ssun));
    }
    if (depth == n)
    {
        return;
    }

    for (int i = idx; i < n; i++)
    {
        result[depth] = {v[i].first, v[i].second};
        func(i + 1, depth + 1);
    }
}

int main(void)
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    func(0, 0);

    cout << ans;
    return 0;
}