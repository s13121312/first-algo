#include <bits/stdc++.h>
using namespace std;

int main(void)
{

    int answer = 0;

    int n;
    cin >> n;
    // 문제 다시읽어라
    string base;
    cin >> base;

    int a = base.length();
    int isused[30];
    for (int i = 0; i < a; i++)
    {
        isused[base[i] - 'A'] += 1;
    }

    for (int k = 0; k < n - 1; k++)
    {
        string str;
        cin >> str;
        int isused2[30];
        for (int i = 0; i < 27; i++)
        {
            isused2[i] = isused[i];
        }

        int same = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (isused2[str[i] - 'A'] > 0)
            {
                isused2[str[i] - 'A']--;
                same++;
            }
        }
        if (str.length() == a)
        {
            if (same == a && same == a - 1) // 길이가 같을때 아예구성이같거나 1개 다를때
            {
                answer++;
            }
        }

        else if (str.length() == a + 1)
        {
            
        }
        else if (str.length() == a - 1)
        {

        }
        else
        {
            // 비슷한단어가아님
            continue;
        }
    }

    cout << answer;

    return 0;
}