#include <bits/stdc++.h>
#include<map>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    map<int, int> mp;
    unordered_map<int,int> um;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        mp[a]++; 
        if(um.find(a) == um.end())um[a] =i+1;
    }

    for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++) {
        cout << it -> first << ' ' << um[it -> first] << '\n';
    }
    return 0;
}