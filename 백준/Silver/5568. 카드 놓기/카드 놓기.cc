#include<bits/stdc++.h>
using namespace std;

//string a, b;

int n, k;
vector<int> v;
unordered_map<string, int> um;
bool vis[12];
void dfs(int depth, string cur) {
    if(depth == k) {
        if(!um[cur]) um[cur]++;
        return;
    }

    for(int i=0;i<n;i++) {
        if(vis[i])continue;
        vis[i] = true;
        dfs(depth+1, cur + to_string(v[i]));
        vis[i] = false;
    }

}

int main(void) {

    cin >> n >> k;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    dfs(0, "");
    int answer = um.size();

    cout << answer;
    return 0;
}


/*int main(void) {
    
    getline(cin, a);
    getline(cin, b);

    int idx = 0;
    int tmp = 0;

    while(1) {
        if(a.find(b, idx) == string::npos)break;
        tmp++;
        idx = a.find(b, idx + b.size());
        cout << idx << ' ';
        
    }
    
    cout << '\n' << tmp;

    return 0;
}*/