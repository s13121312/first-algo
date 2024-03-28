#include <bits/stdc++.h>
using namespace std;



string solution(vector<int> food)
{
    string answer = "";
    for (int i = 1; i <= food.size() - 1; i++)
    {
        for (int j = 0; j < food[i] / 2; j++)
        {
            answer = answer + to_string(i);
        }
    }
    answer += "0";

    for (int i = food.size() - 1; i >= 1; i--)
    {
        for (int j = 0; j < food[i] / 2; j++)
        {
            answer = answer + to_string(i);
        }
    }

    return answer;
}