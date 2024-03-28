#include <bits/stdc++.h>
using namespace std;

int solution(string s)
{
    int answer = 0;

    int xout_cnt = 0;
    int x_cnt = 0;

    char start = s[0];
    if(s.length()==1){
        answer=1;
        return answer;
    }
    for (int i = 0; i < s.size(); i++)
    {

        if (start != s[i])
        {
            xout_cnt++;
            if (x_cnt == xout_cnt)
            {
                start = s[i + 1];
                answer++;
                x_cnt = 0;
                xout_cnt = 0;
            }
        }
        else
        {
            x_cnt++;
        }
    }
    if(x_cnt != xout_cnt) //맞게 끝나지않았을때
    {
        answer++;
    }

    return answer;
}