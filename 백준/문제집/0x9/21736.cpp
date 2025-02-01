#include<bits/stdc++.h>
using namespace std;

int n,m;
char arr[605][605];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool isused[605][605];

bool check = false;
int cnt = 0;

int main(void){

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }


    queue<pair<int,int>> q;
    

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 'I'){
                isused[i][j]=true;
                q.push({i,j});



                while (!q.empty())
                {
                    auto cur = q.front(); q.pop();

                    for(int i=0;i<4;i++){
                        int nx = cur.first + dx[i];
                        int ny = cur.second + dy[i];
                        if(nx <0 || nx>=n || ny<0 || ny>=m)continue;
                        if(isused[nx][ny] || arr[nx][ny] =='X')continue;

                        
                        if(arr[nx][ny]=='P'){
                            cnt++;
                            check = true;
                        }
                        isused[nx][ny]=true;
                        q.push({nx,ny});
                    }

                }
                
            }
        }
    }




    if(!check){
        cout << "TT";
    }
    else{
        cout << cnt;
    }
    return 0;
}