#include <bits/stdc++.h>
using namespace std;

int termnum(int n)
{
    int i = 666;
    int series = 0;

    string target;
    while (1)
    {
        target = to_string(i);
        for (int j = 0; j <= target.length() - 2; j++)
        {
            if (target[j] == '6' && target[j + 1] == '6' && target[j + 2] == '6')
            {
                series++;
                if (series == n)
                {
                    return i;
                }
                break;
            }
            
        }
        i++;
    }

}

int main(void)
{
    int n;
    cin >> n;

    cout << termnum(n);

    return 0;
}