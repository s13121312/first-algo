#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int bongji = 0;
    while (n>=0)
    {
        if(n%5==0){ // 큰걸로 나눔
            bongji += (n/5);
            cout << bongji << '\n';
            return 0;
        }
        n-=3;
        bongji++;
    }
    cout << "-1";


}