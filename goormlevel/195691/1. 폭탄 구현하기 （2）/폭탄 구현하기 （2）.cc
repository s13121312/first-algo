#include<bits/stdc++.h>
using namespace std;

int n, k;
char arr[205][205];
int vis[205][205]={0,};
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void bomb(int x, int y){
    if(arr[x][y] == '0'){
        vis[x][y] += 1;
    }else if(arr[x][y] == '@'){
        vis[x][y] += 2;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<=0 || nx>n || ny<=0 || ny>n || arr[nx][ny] == '#')continue;
        if(arr[nx][ny] == '0')vis[nx][ny]+=1;
        else if(arr[nx][ny] == '@')vis[nx][ny]+=2;
    }

}


void input(){
    
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i=0;i<k;i++){
        int a,b;
        cin >> a >> b;
        bomb(a,b);
    }

    
}

void pro(){
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ans < vis[i][j])ans = vis[i][j];
        }
    }

    cout << ans;
}

int main(){

    input();
    pro();

    return 0;
}