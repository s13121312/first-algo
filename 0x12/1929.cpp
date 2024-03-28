#include <bits/stdc++.h>
using namespace std;

vector<int> func(int n)
{
    vector<int> prime;
    vector<bool> state(n + 1, true);
    state[1] = false;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            if(!state[j]) continue;
            state[j] = false;
        }
    }

    for(int i=2;i<=n;i++){
        if(state[i]){
            prime.push_back(i);
        }
    }
    return prime;

}

int main(void)
{
    int m, n;
    cin >> m >> n;
    vector<int> prime;

    prime = func(n);
    for(int i=0;i<=n;i++){
        if(prime[i]>=m && prime[i]<=n){
            cout<< prime[i]<< '\n';
        }
    }    

}