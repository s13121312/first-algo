#include<bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> um;

int main(void) {

    cin >> n;
    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        um[str]++;

    }
    for(int i=0;i<n-1;i++) {
        string str;
        cin >> str;
        um[str]--;
    }


    for(unordered_map<string, int>:: iterator it = um.begin();it != um.end();it++) {
        if(it->second == 1) {
            cout << it->first;
            break;
        }
    }

    return 0;
}