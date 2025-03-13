#include <bits/stdc++.h>
using namespace std;
int n, m;
priority_queue<tuple<int, int, int> > pq;

int main() {
    // Please write your code here.
    
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int x, y;
        cin >> x >> y;
        pq.push(make_tuple(-(x+y), -x, -y));
    }

    while(m--) {
        int x, y;
        tie(ignore, x, y) = pq.top();
        pq.pop();
        x = -x, y = -y;
        x += 2, y += 2;
        pq.push(make_tuple(-x-y, -x, -y));

    }
    int lx, ly;
    tie(ignore, lx, ly) = pq.top();
    cout << -lx << ' ' << -ly;

    return 0;
}