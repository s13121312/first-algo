#include <bits/stdc++.h>
using namespace std;

vector<int> p[1005];
bool visited[1005];
int n, m;

void input(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;
        p[x].push_back(y);
        p[y].push_back(x);
    }
}
int cnt = 0;

void pro(int vertex){
    for(int i=0;i<p[vertex].size();i++){
        if(!visited[p[vertex][i]]){
            visited[p[vertex][i]]= true;
            cnt++;
            pro(p[vertex][i]);
        }

    }
}

int main() {
    // Please write your code here.
    input();
    pro(1);
    if(cnt-1 == -1){
        cout << 0;
    } else {
        cout << cnt-1;
    }
    return 0;
}