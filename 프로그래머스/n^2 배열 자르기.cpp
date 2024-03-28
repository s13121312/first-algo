#include<bits/stdc++.h>

using namespace std;


vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    vector<vector<int>> tmp2(n+1,vector<int> (n+1,0));
    vector<int> tmp1;
    for(int i=1;i<=n;i++){
        for(int j =1;j<=i;j++){
            if(tmp2[i][j]>0)continue;
            if(tmp2[i][j] == 0){
                tmp2[i][j] = i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
            tmp1.push_back(tmp2[i][j]);
        }
    }
    for(int i=left;i<=right;i++){
        answer.push_back(tmp1[i]);
    }
    
    return answer;
}