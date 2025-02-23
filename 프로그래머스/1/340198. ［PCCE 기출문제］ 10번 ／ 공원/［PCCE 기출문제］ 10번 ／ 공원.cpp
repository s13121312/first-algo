#include <bits/stdc++.h>
#include <vector>

using namespace std;
int n, m;

bool cmp(int a, int b){
    return a > b;
}

bool isavailable(vector<vector<string>>& park, int i, int j, int l) {
    bool chk = false;
    for(int a=i;a<i+l;a++){
        for(int b =j;b<j+l;b++){
            if(a<0 || a>=n || b<0 || b>=m)continue;
            if(park[a][b] != "-1")return false;
        }
    }
    return true;
}

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    n = park.size();
    m = park[0].size();
    
    sort(mats.begin(), mats.end(), cmp);
    for(int l : mats) {
        for(int i=0;i<=n-l;i++) {
            for(int j=0;j<=m-l;j++) {
                if(isavailable(park, i,j, l))answer = max(answer, l);
            }
        }
    }
    
    if(answer == 0)return -1;
    return answer;
}