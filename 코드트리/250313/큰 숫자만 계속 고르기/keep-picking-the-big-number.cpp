#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
int main() {
    // Please write your code here.

    priority_queue<int> pq;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
        pq.push(a);
    }



    while(m--) {
        int tmp = pq.top()-1;
        pq.pop();
        pq.push(tmp);
    }

    cout << pq.top();
    
    return 0;
}