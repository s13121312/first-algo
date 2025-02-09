#include <bits/stdc++.h>
using namespace std;



int main() {
    // Please write your code here.

    int n;
    cin >> n;

    map<string, int> mp;

    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        mp[str]++;
    }

    cout << fixed << setprecision(4);

    for(map<string,int>::iterator it = mp.begin();it != mp.end();it++) {
        double ans = 100.0 * it -> second / n;
        cout << it->first << ' ' << ans << '\n';
    }

    return 0;
}