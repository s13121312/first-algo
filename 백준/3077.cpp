#include<bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int> um;
vector<string> v;
vector<string> s;
int main(void) {

    cin >> n;
    for(int i=0;i<n;i++){
        string str;
        cin >> str;
        v.push_back(str);
        um[str] = i;
    }

    for(int i=0;i<n;i++) {
        string str;
        cin >> str;
        s.push_back(str);
    }
    
    int score = 0;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(um[s[i]] < um[s[j]])score++;
        }
    }

    int ans2 = (n*(n-1)/2);
    cout << score << '/' << ans2;

    return 0;
}