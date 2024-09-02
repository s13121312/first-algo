#include <bits/stdc++.h>
using namespace std;

int ans = 1;
int dp[1005];
// dp[i]는 i번째로 끝나는 것중에 가장 긴 부분 팰린드롬 문자열의 길이
string str;
int n;

void input()
{
    cin >> str;
    n = str.size();
}

bool is_palind(string tmp)
{
    string str1, str2;
    str1 = tmp;
    int k = tmp.size();
    for (int i = k - 1; i >= 0; i--)
    {
        str2 += tmp[i];
    }

    if (str1 == str2)
        return true;
    return false;
}

void pro()
{

    for (int i = 0; i < n; i++)
    {
        string tmp = "";
        tmp = str[i];
        for (int j = i + 1; j < n; j++)
        {
            tmp += str[j];

            if (is_palind(tmp))
            {
                int s = tmp.size();
                ans = max(ans, s);
            }
        }
    }

    cout << ans;
}

int main()
{

    input();
    pro();


    return 0;
}
