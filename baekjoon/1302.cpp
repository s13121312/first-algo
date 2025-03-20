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
    string an;
    int ans = 0;
    for(unordered_map<string,int>::iterator it = um.begin();it!=um.end();it++) {
        if(ans < it-> second) {
            an = it -> first;
            ans = it -> second;
        }
    }

    cout << an;
    
    return 0;
}