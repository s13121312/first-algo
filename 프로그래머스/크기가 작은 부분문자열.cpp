#include <bits/stdc++.h>
using namespace std;

long long l;
int answer = 0;
long long change(string t)
{
    // 문자열을 숫자로 바꿔주는 함수
    long long tmp = 0;
    for (int i = 0; i <= t.length() - 1; i++)
    {
        tmp = tmp * 10 + t[i] - '0';
    }
    return tmp;
}

long long solution(string t, string p)
{

    l = p.length();

    string tmp;

    // 길이가 l인 부분문자열 구하고
    for (int i = 0; i <= t.length() - l; i++)
    {
        tmp = t.substr(i, l);
        // 나온것에서 change로변환
        if (change(tmp) <= change(p))
        {
            cout << tmp<<'\n';
            answer++;
        }
    }

    return answer;
}

int main(void){

    string t="10203";
    string p="15";

    cout << solution(t,p);

    return 0;
}

