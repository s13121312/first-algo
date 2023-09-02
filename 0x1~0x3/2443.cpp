#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for(int i=N; i>0; i--)
    {
        for(int k=N-i;k>0; k--)
        {
            cout << " ";
        }
        for(int k=2*i-1;k>0;k--)
        {
            cout << "*";
        }        
        cout<<"\n";
    }
    return 0;
}