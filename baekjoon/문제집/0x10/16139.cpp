#include <bits/stdc++.h>
using namespace std;

int ps[26][200005]; // 무슨 알파벳인지 , 몇번째에 위치하는지
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (i != 0)
        {
            // 앞에 가지고있던거를 계속 가지고있어야함으로
            for (int j = 0; j < 26; j++)
            {
                ps[j][i] = ps[j][i - 1];
            }
        }
        ps[s[i] - 'a'][i]++;
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        char input;
        int l, r;
        cin >> input >> l >> r;
        if (l == 0)
        {
            cout << ps[input - 'a'][r] << '\n';
        }
        else
        {
            cout << ps[input - 'a'][r] - ps[input - 'a'][l - 1] << '\n';
        }
    }

    return 0;
}