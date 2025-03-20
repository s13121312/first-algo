#include<bits/stdc++.h>
using namespace std;

int t;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        unordered_map<int, int> um1;
        unordered_map<int, int> um2;
        int n, m;
        cin >> n;
        for(int i=0;i<n;i++) {
            int a;
            cin >> a;
            um1[a]++;
        }

        cin >> m;
        for(int i=0;i<m;i++) {
            int a;
            cin >> a;
            if(um1.find(a) != um1.end()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
    

    return 0;
}