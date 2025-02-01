#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string input;

long long word(int mo_num, int ja_num, int L_chk, int depth)
{
    if (mo_num >= 3)
    {
        return 0;
    }
    if (ja_num >= 3)
    {
        return 0;
    }

    if (depth == input.size())
    {

        if (L_chk == 0)
            return 0;
        else
            return 1;
    }
    long long ret = 0;

    if (input[depth] != '_')
    {
        if (input[depth] == 'A' || input[depth] == 'E' || input[depth] == 'I' || input[depth] == 'O' || input[depth] == 'U')
        {
            ret = word(mo_num + 1, 0, L_chk, depth + 1);
        }
        else
        {
            if (input[depth] == 'L')
            {
                ret = word(0, ja_num + 1, L_chk + 1, depth + 1);
            }
            else
            {
                ret = word(0, ja_num + 1, L_chk, depth + 1);
            }
        }
    }
    else
    { //  _라면   알파벳 26 모음 5개 자음21개
        // 모음일때
        ret += (5 * word(mo_num + 1, 0, L_chk, depth + 1));
        // 자음
        ret += (20 * word(0, ja_num + 1, L_chk, depth + 1));
        // 자음 & L
        ret += (1 * word(0, ja_num + 1, L_chk + 1, depth + 1));
    }

    return ret;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> input;
    cout << word(0, 0, 0, 0);

    return 0;
}