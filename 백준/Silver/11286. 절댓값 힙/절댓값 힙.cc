#include<bits/stdc++.h>
using namespace std;

int n;

struct cmp {
    bool operator() (const int& a, const int& b) {
        if(abs(a) != abs(b)) {
            return abs(a) > abs(b);
        }
        return a > b;
    }
    
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    cin >> n;
    priority_queue<int, vector<int>, cmp> pq;

    while(n--) {
        int x;
        cin >> x;
        if(x == 0) {
            if(!pq.empty()) {
                cout << pq.top() << '\n';
                pq.pop();
            } else cout << 0 << '\n';
        }
        else pq.push(x);
    }

    return 0;
}