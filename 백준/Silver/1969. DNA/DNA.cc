#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int n, m;

bool cmp(pair<string, int>& p1, pair<string, int>& p2) {
    if(p1.second == p2.second)return p1.first < p2.first;
    return p1.second < p2.second;
}

int main() {

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    string res;
    for(int l=0;l<m;l++) {
        unordered_map<char, int> um;
        char maxChar;
        int maxCnt = 0;
        for(int i=0;i<v.size();i++) {
            um[v[i][l]]++;
            if(maxCnt <= um[v[i][l]]) {
                if(maxCnt == um[v[i][l]]){
                    if(maxChar> v[i][l]) {
                        maxChar = v[i][l];
                    }
                } else {
                    maxChar = v[i][l];
                    maxCnt = um[v[i][l]];
                }
            }
        }
        res += maxChar;
    }
    cout << res << '\n';

    for(int i=0;i<v.size();i++) {
        for(int j=0;j<m;j++) {
            
        }
    }

    int c = 0;
    for(int i=0;i<v.size();i++) {
        
        for(int l = 0;l<m;l++) {
            if(v[i][l] != res[l]) {
                c++;
            }
        }
    }
    cout << c;
    // sort(result.begin(), result.end(), cmp);
    // for(auto s : result) {
    //     cout << s.first << ' ' << s.second << '\n';
    // }
    //cout << result[0].first << '\n' << result[0].second;

    return 0;
}