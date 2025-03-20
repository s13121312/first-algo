#include<bits/stdc++.h>
using namespace std;

int n, m, k;
char arr[12][12];
unordered_map<string, int> um;
int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,-1,-1,-1,0,1,1,1};
int likestrSize;

void dfs(int x, int y, string word) {
    if(word.size() > 5) return;
    um[word]++;

    for(int d=0;d<8;d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(nx<0)nx=n-1;
        if(nx>=n) nx = 0;
        if(ny<0) ny = m-1;
        if(ny>=m) ny = 0;
            
        dfs(nx,ny, word + arr[nx][ny]);
    }
}



int main() {

    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> arr[i][j];
        }
    }
    vector<string> likestr;
    for(int i=0;i<k;i++) {
        string s;
        cin >> s;
        
        likestr.push_back(s);
    }
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            //i,j가 시작점
            
            dfs(i, j, string(1, arr[i][j]));
        }
    }

    //cout << um.size() << '\n';
    
    for(auto l : likestr) {
        cout << um[l] << '\n';
    }

    return 0;
}