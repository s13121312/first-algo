#include <bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<int> section)
{
    int answer = 0;
    bool arr[100005]; // 페인트칠한곳
    fill(arr, arr + 100005, true);
    for (int i = 0; i < section.size(); i++)
    {
        arr[section[i]] = false;
    }

    for (int i = section[0]; i <= section[section.size() - 1]; i++)
    {
        if (arr[i])
            continue; // 이미 칠해져있으면 넘어가고

        for (int j = i; j < i + m; j++)
        {
            if(j>n)continue;//범위 고려
            arr[j] = true;
        }
        answer++;
    }

    return answer;
}