#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> um;
vector<int> v;
int n, k, arr[100005];

void input() {
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        if(um.find(arr[i]) != um.end()) {
            um[arr[i]]++;

        } else {
            v.push_back(arr[i]);
            um[arr[i]]++;
        }
    }
}

bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second == p2.second)return p1.first > p2.first;
    return p1.second > p2.second;
}
vector<pair<int, int>> p;
void pro() {

    for(int i=0;i<v.size();i++) {
        p.push_back({v[i], um[v[i]]});
    }

    sort(p.begin(), p.end(), cmp);

    for(int i=0;i<k;i++) {
        cout << p[i].first << ' ';
    }
}

int main() {
    // Please write your code here.
    input();
    pro();

    return 0;
}