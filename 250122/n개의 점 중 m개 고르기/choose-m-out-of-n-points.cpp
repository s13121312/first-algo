#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> p[25];
vector<int> selected;
int ans = 0x7fffffff;

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int x, y;
        cin >> p[i].first >> p[i].second;
    }
}
int calcDist(int x1,int x2, int y1, int y2){
    return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int findMaxDist(){
    int maxD = 0;
    for(int i=0;i<m-1;i++){
        for(int j=i+1;j<m;j++){
            int idx = selected[i];
            int jidx=selected[j];
            maxD = max(maxD, calcDist(p[idx].first, p[jidx].first, p[idx].second, p[jidx].second));
        }
    }
    return maxD;
}

//고른 점 개수 cnt
void pro(int depth, int cnt){
    if(cnt == m){
        ans = min(ans, findMaxDist());
    }

    if(depth == n)return;

    selected.push_back(depth);
    pro(depth+1, cnt+1);
    selected.pop_back();

    pro(depth+1, cnt);
}

int main() {
    // Please write your code here.
    input();
    pro(0,0);
    cout << ans;
    return 0;
}