#include <bits/stdc++.h>
using namespace std;

vector<int> func(int n)
{
    vector<int> tmp;

    for (int i = 2; i * i <= n; i++)
    {
        while (1)
        {
            if (n % i == 0)
            {
                n /= i;
                tmp.push_back(i);
            }
            if(n%i != 0){
                break;
            }
        }
    }
    if(n != 1){
        tmp.push_back(n);
    }

    return tmp;
}

int main(void)
{

    int n;
    cin >> n;
    vector<int> a;
    a=func(n);

    for(int i=0;i<a.size();i++){
        cout << a[i] << '\n';
    }

    return 0;
}