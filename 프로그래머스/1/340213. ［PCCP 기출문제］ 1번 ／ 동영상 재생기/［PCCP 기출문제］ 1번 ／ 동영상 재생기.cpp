#include <bits/stdc++.h>
using namespace std;

string answer = "";
string tmp;

int tchange(string a)
{
    int ca = 60 * stoi(a.substr(0, 2)) + stoi(a.substr(3, 2)); // 초단위로
    return ca;
}

// 비디오의 총 길이보다 작은지 0초보다 큰지 확인하는 함수.
bool outofrange(int t, string video_len)
{
    int vl = tchange(video_len);
    if (t + 10 > vl || t - 10 < 0)
    {
        // 범위를 벗어남.
        return true;
    }
    return false;
}

void timepm(string &t, string type, string video_len)
{

    int newt = tchange(t);
    if (type == "minus")
        newt -= 10;
    else if (type == "plus")
        newt += 10;

    // 여기서 판별하고
    if (outofrange(newt, video_len))
    {
        if(newt - 10 < 0){
            // 10초 빼보고 0 범위를 벗어나면 00초로 세팅.
                t = "00:00";
        }else{
            t = video_len; // 영상의 마지막 위치로 이동
        }
    }
    else
    {
        int min = newt / 60;
        int sec = newt % 60;
        string s1, s2;

        if (min < 10)
        {
            s1 = "0" + to_string(min);
        }
        else
            s1 = to_string(min);
        if (sec < 10)
        {
            s2 = "0" + to_string(sec);
        }
        else
            s2 = to_string(sec);

        t = s1 + ":" + s2;
    }
    
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands)
{
    
    tmp = pos;

    for (auto x : commands)
    {
        cout << tmp << '\n';
        if (tchange(tmp) >= tchange(op_start) && tchange(tmp) <= tchange(op_end))
        {
            // 오프닝 사이에 있는지 확인 -> 그러면 현재 시간을 op_end로
            tmp = op_end;
        }
        if (x == "prev")
        {
            // 10초 감소하고
            timepm(tmp, "minus", video_len);   
        }
        else if (x == "next")
        {
            timepm(tmp, "plus", video_len);   
        }
    }
    if (tchange(tmp) >= tchange(op_start) && tchange(tmp) <= tchange(op_end))
    {
        // 오프닝 사이에 있는지 확인 -> 그러면 현재 시간을 op_end로
        tmp = op_end;
    }

    answer = tmp;
    return answer;
}