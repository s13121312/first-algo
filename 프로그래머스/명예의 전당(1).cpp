#include <bits/stdc++.h>
using namespace std;

void func()
{
}
bool cmp(int a, int b)
{
    return a > b;
}
vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    vector<int> legend;
    int m;
    for (int i = 0; i < score.size(); i++)
    {
        if (i + 1 <= k)
        {
            legend.push_back(score[i]);
            sort(legend.begin(), legend.end(), cmp);
            answer.push_back(legend[i]);
        }
        // 명예의 전당과  k번째 순위의 가수 점수보다 더 높으면 점수 비교
        if (i + 1 > k)
        {
            if (legend[k-1] < score[i])
            {
                legend.pop_back();
                legend.push_back(score[i]); 
                sort(legend.begin(), legend.end(), cmp);
            }
            answer.push_back(legend[k-1]);
        }
        
    }

    return answer;
}
