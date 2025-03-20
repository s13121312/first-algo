#include <bits/stdc++.h>
using namespace std;

int n;

priority_queue<int, vector<int>, greater<int>> pq; 
int main() {
    // Please write your code here.

    cin >> n; 
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    priority_queue<float> res;

    for(int k=1;k<=n-2;k++) {
        priority_queue<int, vector<int>, greater<int>> tmp;
        tmp = pq;
        for(int j=0;j<k;j++)tmp.pop(); 
        float s = tmp.size();
        float sum = 0;
        while(!tmp.empty()) {
            sum += tmp.top();
            tmp.pop();
        }
        res.push(sum / s);
    }

    cout << fixed;
    cout.precision(2);
    cout << res.top();

    return 0;
}