#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;




int main(void)
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
    }

    for(int i=0;i<n-1;i++){
        pq.pop();
    }
    int ans = pq.top();
    cout << ans;

    return 0;
}