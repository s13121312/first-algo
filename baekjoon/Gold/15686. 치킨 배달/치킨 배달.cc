#include<bits/stdc++.h>
using namespace std;


//0은 빈 칸, 1은 집, 2는 치킨집
//치킨 거리를 구하는 함수 
//brute 로 m개 구했을때 치킨거리들 중 최솟값
int board[55][55];
int n, m;
bool vis[55][55];
int ans = 0x7fffffff;
vector<pair<int, int>> chickenhouse;
vector<pair<int, int>> choosen;

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j] == 2){
                chickenhouse.push_back({i,j});
            }
        }
    }
}

void pro(){
    cout << ans;
}

int distcalc(pair<int, int> p1, pair<int, int> p2){
    return (abs(p1.first-p2.first))+(abs(p1.second - p2.second));
}

int chickenDistance(vector<pair<int,int>> choosen){

    int totalDistance = 0;

    //골라진 m개의 치킨거리를 구하면됨
    //집을 기준으로 치킨거리가 구해짐.
    //초반에 치킨집을 기준으로 구했어서 
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == 1){
                int mindist =0x7fffffff;
                for(auto chicken : choosen){
                    int d = distcalc({i,j}, chicken);
                    mindist = min(mindist, d);
                }
                totalDistance += mindist;
            }
        }
    }
    
    return totalDistance;
}

void dfs(int start, int curm){
//치킨집 m개를 골라야함

    if(curm == m){
        //치킨 거리 계산 후 ans와 비교
        ans = min(ans, chickenDistance(choosen));
        return;
    }
    //조합은 순서에 상관없이 뽑기만한다. 순서에 상관없다는말은 123,321이런 순서를 신경쓰지않고 그냥뽑는다라는 행위
    //순열은 순서에 상관있게 뽑는다.

    for(int i=start;i<chickenhouse.size();i++){
        if(find(choosen.begin(), choosen.end(), chickenhouse[i]) != choosen.end())continue;
        choosen.push_back(chickenhouse[i]);
        dfs(i+1, curm + 1);
        //dfs(i,curm+1)과의 차이는 중복이되냐안되냐의 차이가난다. 
        //중복을 피해주려면 dfs(i+1, curm+1)을 한줄로 하던가 아니면
        //if(find(choosen.begin(), choosen.end(), chickenhouse[i]) != chickenhouse.end())continue;
        //위를 거쳐서 들어오던가 둘 중 하나를 선택하면됨
        choosen.pop_back();
    }

}

int main(){

    input();
    
    dfs(0,0);
    pro();


    return 0;
}

