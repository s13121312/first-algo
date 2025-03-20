#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string,int> mp;
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        mp[str]++;
    }

    for(map<string, int>::iterator it=mp.begin();it!=mp.end();it++) {
        cout << it -> first << ' ' << it -> second << '\n';
    }
    // Please write your code here.
    return 0;
}