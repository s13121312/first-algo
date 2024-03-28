#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    vector<int> weight(241);

    for (int i = 0; i < people.size(); i++)
    {
        weight[people[i]]++;
    }

    for (int i = 0; i < people.size(); i++)
    {
        if (weight[people[i]]>0) // 아직 안 쓰였을때
        {
            weight[people[i]]--;

            for (int j = limit - people[i]; j >= 40; j--)
            {
                if (weight[j] > 0)
                { // 두개 태울수있으면
                    weight[j]--;
                    break;
                }
            }
            answer++;
        }
        
    }

    return answer;
}
