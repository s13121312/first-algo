#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> pq;
int main() {
    // Please write your code here.

    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    while(1) {
        if(pq.size() == 1)break;
        if(pq.empty()) {
            cout << -1;
            break;
        }
        int t1 = pq.top();
        pq.top();
        int t2 = pq.top();
        
        if(t1 == t2) {
            pq.pop();
            continue;
        } else {
            pq.push(t1-t2);
        }
    }
    if(!pq.empty())cout << pq.top();

    return 0;
}