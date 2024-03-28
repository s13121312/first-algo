#include<bits/stdc++.h>
using namespace std;


int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(),score.end());

    int s = score.size();
    
    if(s % m !=0){
        for(int i=s-1;i>=m-1;i-=m)
        {
            answer += score[i-m+1]*m;
        }
        
    }
    else{ //상자 개수인 m으로 딱 나눠떨어질때
        for(int i=0;i<s;i+=m){
            answer += score[i]*m;
        }
    }
    return answer;
}