#include <bits/stdc++.h>
using namespace std;

int answer = 0x7f7f7f7f;

//숙련도의 최솟값이 얼마가 되어야 퍼즐을 모두 해결하는가?

bool determination(int mid, vector<int> diffs, vector<int> times, long long limit)
{
    int n = diffs.size();
    long long t = 0; // 혹시 모르니까 걸린 시간은 이렇게 잡음
    for (int i = 0; i < n; i++)
    { // n은 안봤음 나중에 따로 처리해줘야함.
        if (mid >= diffs[i])
        {
            t += times[i];
        }
        else
        {
            t += (diffs[i] - mid) * (times[i] + times[i - 1]) + times[i];
        }
    }

    if (t <= limit)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solution(vector<int> diffs, vector<int> times, long long limit)
{
    int n = times.size();

    int l = 1, r = 100000;

    // 1부터 확인한다?
    while (l <= r)
    {
        int mid = (l + r) / 2;

        if(determination(mid, diffs, times, limit)){
            r = mid - 1; //왜 r을 건드려야하나? 
// ->우리는 최솟값을 찾는것이 목표인데 determination안에서 limit보다 작거나 같을때 true를 반환하니까
// 우리는 r범위를 줄여서 더 작은값을 찾아야함 l을 건드리는건 더 큰값을 찾으려고 할때 써야함.
            answer = min(answer, mid);
            cout << answer << '\n'; //갱신이 안되고 있음 50000만 계속나오는데..
        }else{
            l = mid + 1;
        }
    }
    return answer;
}