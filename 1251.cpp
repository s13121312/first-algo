#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b)
{
    return a < b;
}
int main(void)
{

    string input;
    cin >> input;

    vector<string> v;

    // tmp는 tmp1~3들 reverse한것 더한것 v에 넣어서 정렬시킨후 가장 처음것 출력
    string t;

    for (int i = 2; i <= input.size() - 1; i++)
    {

        for (int j = 1; j < i; j++)
        {
            string tmp1;
            string tmp2;
            string tmp3;
            tmp1 += input.substr(0, j);
            tmp2 += input.substr(j, i-j);
            tmp3 += input.substr(i);

            reverse(tmp1.begin(), tmp1.end());
            reverse(tmp2.begin(), tmp2.end());
            reverse(tmp3.begin(), tmp3.end());
            t = tmp1 + tmp2 + tmp3;
            v.push_back(t);
        }
    }

    sort(v.begin(), v.end(), cmp);

    cout << v[0];
    return 0;
}