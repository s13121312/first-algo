#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    int day = 0;
    vector<int> tmp;
    for (int i = 0; i < progresses.size(); i++)
    {
        day = 0;
        int k = 100 - progresses[i];
        day += (k / speeds[i]);
        if (k % speeds[i] > 0)
        {
            day++;
        }
        tmp.push_back(day);
    }

    queue<int> q;

    q.push(tmp[0]);
    for (int i = 1; i < tmp.size(); i++)
    {
        if (q.front() >= tmp[i])
        {
            q.push(tmp[i]);
        }
        else
        {
            answer.push_back(q.size());
            while (!q.empty())
            {
                q.pop();
            }
            q.push(tmp[i]);
        }
        break;
    }

    // 남은거 처리
    if (!q.empty())
    {
        answer.push_back(q.size());
    }

    return answer;
}