#include <bits/stdc++.h>
using namespace std;
int n;

vector<int> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    // Please write your code here.

    cin >> n;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(x == 0) {
            if(pq.empty())cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            } 
        } else {
            pq.push(x);
        }
        
    }


    return 0;
}