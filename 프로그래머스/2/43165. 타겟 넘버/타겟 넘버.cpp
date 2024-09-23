#include<bits/stdc++.h>
using namespace std;


int ans = 0;
bool vis[22];



void dfs(int now, int cur, int target, vector<int> numbers){

    if(now == numbers.size()){
        if(cur == target)ans++;
        return;
    }

    /*for(int i=0;i<numbers.size();i++){
        //+, -처리해줘야함
        if(!vis[i]){
            vis[i] = true;
            dfs(now+1, cur + numbers[i], target, numbers);
            dfs(now+1, cur - numbers[i], target, numbers);
            vis[i] = false;
        }
    }*/ //<-이렇게 해버리면 전부 탐색하게됨 (불필요한 탐색)
    dfs(now+1, cur + numbers[now], target, numbers);
    dfs(now+1, cur - numbers[now], target, numbers);
}

int solution(vector<int> numbers, int target) {

    dfs(0, 0, target, numbers);

    return ans;
}