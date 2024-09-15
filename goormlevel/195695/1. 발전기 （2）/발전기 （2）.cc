#include<bits/stdc++.h>
using namespace std;

int arr[1005][1005];
int n, k;
unordered_map<int,int> um;
bool vis[1005][1005];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

vector<int> numb;

void input(){
    cin >> n >> k; //k개이상이면 단지 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}


void bfs(int x, int y, int bunho){

    //bunho가없으면 numb에추가.
    if(find(numb.begin(),numb.end(), bunho) == numb.end())numb.push_back(bunho);

    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = true;

    int tmp = 0;

    while (!q.empty())
    {   
        auto cur = q.front();
        q.pop();
        tmp++;
        for(int i=0;i<4;i++){
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=n)continue;
            if(arr[nx][ny] != bunho || vis[nx][ny])continue;

            q.push({nx,ny});
            vis[nx][ny] = true;
        }
    }

    if(tmp >= k){
        //단지가될수있음
        um[bunho]++;
    }
    

}

void pro(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j]){
                bfs(i,j,arr[i][j]);
            }
        }
    }

    pair<int, int> ans;
    for(auto x : numb){
        if(ans.second < um[x]){
            ans = {x, um[x]};
        }else if(ans.second == um[x]){
            if(ans.first < x)ans = {x, ans.second}; //같을때는 더 큰단지번호가 답.
        }
    }

    cout << ans.first;


}

int main(){

    input();
    pro();
    
    return 0;
}