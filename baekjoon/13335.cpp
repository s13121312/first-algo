#include <bits/stdc++.h>
using namespace std;

int n, w, l;
vector<int> v;

void input()
{

    cin >> n >> w >> l;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
}
// 트럭은 1초에 다리 길이 1씩 전진한다.
// 트럭은 올라갈수 있으면 1초에 한 대씩 다리에 올라갈 수 있다
void pro()
{

    int totalw = 0; // 현재 큐에 들어가 있는(다리 위에 있는 차들의의) 무게
    queue<pair<int, int> > q;   // {트럭의인덱스, 다리에 진입한 시간} 
    int t = 0;   // 시간(초)
    int idx = 0; // 몇번 째 차인지

    //w가 다리의 길이, l은 최대 하중(무게)

    while (1)
    {
        t++;

        //다리길이보다 크면 트럭이 빠져나간거거
        if(!q.empty() && t - q.front().second >= w) {
            totalw -= v[q.front().first];
            q.pop();
        }

        // 다리위의 차들 총 무게 + 들어올 차 무게 <= l  && 다리위에 올라가있는 차 개수+1 <= w
        if (idx < n && totalw + v[idx] <= l && (q.size() + 1) <= w)    
        {
            q.push({idx, t}); // 들어간 시점 큐에 추가
            totalw += v[idx++];
        }

        if (idx == n && q.empty())break;
    }
    cout << t;
}

int main(void)
{

    input();
    pro();

    return 0;
}