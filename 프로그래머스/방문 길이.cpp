#include<bits/stdc++.h>
using namespace std;

bool iswalked[10][10]={false, };

int solution(string dirs) {
    int answer = 0;

    queue<pair<int,int>> q;
    iswalked[0][0]= true;
    q.push({0,0});

    
    for(int i=0;i<dirs.size();i++){
        pair<int,int> cur = q.front();
        if(dirs[i]=='L'){
            if()

        }
        if(dirs[i]=='U'){
            
        }
        if(dirs[i]=='D'){
            
        }
        if(dirs[i]=='R'){
            
        }
    }

    return answer;
}