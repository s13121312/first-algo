#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int brown, int yellow)
{
    vector<int> answer;
    int area = brown + yellow;
    // garo는가로 sero는 세로
    for (int garo = 3; garo <= area; garo++)
    {
        if (area % garo == 0)
        {
            int sero = area / garo;
            if (garo >= sero && 2 * (garo + sero - 2) == brown && (garo - 2) * (sero - 2) == yellow)
            {
                answer.push_back(garo);
                answer.push_back(sero);
                break;
            }
            
        }
    }
    return answer;
}


