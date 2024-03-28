//왜 안되는걸까??
//7번줄에서 벡터를 v(10)으로 선언했기 때문에 벡터 v에 0이 10개가 들어있는 상태입니다. 그래서
//20을 한번 더 중복으로 연산하는 0 0 ... 0 20 1 15 4 10 8이 최댓값으로 출력되고 있습니다.

#include <bits/stdc++.h>
using namespace std;

int arr[10];
bool isused[10];
int n;
vector<int> v;

int ans = 0;

void func(int depth)
{

    if (depth == n)
    {
        int tmp = 0;
        for (int i = 0; i < v.size() - 1; i++)
        {
            tmp += abs(v[i] - v[i + 1]);
        }
        ans = max(ans, tmp);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if(isused[i])continue;
        isused[i] = true;
        v.push_back(arr[i]);
        func(depth + 1);
        
        v.pop_back();
        isused[i] = false;
    }
}

int main(void)
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    func(0);

    cout << ans;

    return 0;
}