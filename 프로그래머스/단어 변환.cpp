//다시 풀기
#include <bits/stdc++.h>
using namespace std;

bool check(string a, string b)
{ // 한개만 차이나는 단어 판별
    int cnt = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            cnt++;
    }

    if (cnt == 1)
        return true;
    else
        return false;
}
int answer = 1e9;

// 한번 사용한 단어는 재사용하지 않는것이 암묵적인 규칙임을 알 수 있다.
//(단어를 재사용하면 변환단계가 더 길어지므로 최소값이 될 수 없으므로 해가 될 수 없다.)
bool isused[60];
void func(int depth, string &begin, string &target, vector<string> &words)
{

    if (begin == target)
    {
        answer = min(answer, depth);
        return;
    }

    for (int i = 0; i < words.size(); i++)
    {
        if (check(begin, words[i]) && !isused[i])
        {
            isused[i] = true;
            func(depth + 1, words[i], target, words);
            isused[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{

    int cc = 0;
    int chc = 0;
    for (int i = 0; i < words.size(); i++)
    {
        if (words[i] == target)
            chc++;
    }
    if (chc == 0)
        return 0; // target값이없거나 그냥 리턴

    func(0, begin, target, words);

    return answer;
}