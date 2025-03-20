#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b)
{
    //길이순
    if (a.length() != b.length()){
        return a.length() < b.length();
    }
    //길이 같으면 숫자인거만더해서합비교
    int suma = 0;
    int sumb = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i]>='0' && a[i]<='9')
        {
            suma += (a[i] - '0');
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i]>='0' && b[i]<='9')
        {
            sumb += (b[i] - '0');
        }
    }
    if (suma != sumb)return suma < sumb;

    return a < b;//사전순
}
string arr[52];

int main(void)
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        arr[i] = a;
    }

    sort(arr, arr + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << '\n';
    }
    return 0;
}

