#include<bits/stdc++.h>
using namespace std;

int answer = -1;
bool vis[10];

void dfs(int cur, int piro, int tmp, vector<vector<int>> dungeons){
    //이렇게 하면 던전이 3개가 있는데 2개가 최대이면 그 값을 못찾음.
    // if(cur == dungeons.size()){
    //     cout << piro << '\n';
    //     answer = max(answer, tmp);
    //     return;
    // }
    if(tmp > answer)answer = tmp;

    //이렇게 하면 방문한 0번 방문하고 또 0번방문할 수 있음
    for(int i=0;i<dungeons.size();i++){
        if(!vis[i] && piro >= dungeons[i][0]){
            vis[i] = true;
            dfs(cur+1, piro - dungeons[i][1], tmp+1, dungeons); //다음 번으로.
            vis[i] = false;
        }
    }

}

//백트래킹 문제인거같으니 풀때 참고
int solution(int k, vector<vector<int>> dungeons) {
    


    dfs(0, k, 0, dungeons);

    return answer;
}