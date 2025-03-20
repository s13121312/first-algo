#include <bits/stdc++.h>
using namespace std;

int l, c;
char input[20];
char arr[20];
bool isused[20];

bool mj(char arr[20])
{
    int mcnt = 0;
    int jcnt = 0;

    for (int i = 0; i < l; i++)
    {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
        {
            mcnt++;
        }
        else
        {
            jcnt++;
        }
    }
    if (mcnt >= 1 && jcnt >= 2)
    {
        return true;
    }
    return false;
}

void func(int depth,int st)
{
    if (depth == l)
    {
        if (mj(arr)) // 마지막에 검사하기로
        {
            for (int i = 0; i < l; i++)
            {
                cout << arr[i];
            }
            cout << '\n';
        }
    }

    // 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성
   
    for (int i = st; i < c; i++)
    {
        if (!isused[i]) //알파벳 순서
        {
            arr[depth] = input[i];
            isused[i] = 1;
            func(depth + 1, i+1);
            isused[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> input[i];
    }
    sort(input, input + c);
    func(0,0);

    return 0;
}