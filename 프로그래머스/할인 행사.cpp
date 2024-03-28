#include <string>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


bool check(vector<int> &a){
    bool ch = true;
    for(int i=0;i<a.size();i++){
        if(a[i]>0){
            ch = false;
            break;
        }
    }
    return ch;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    vector<int> tmp;
    
    for(int i=0;i<=discount.size()-10;i++){
        tmp=number; //초기화
        for(int j=i;j<i+10;j++){
            //없으면
            if(find(want.begin(),want.end(),discount[j])!=want.end()){
                int idx = find(want.begin(),want.end(),discount[j])-want.begin();
                if(tmp[idx] > 0)tmp[idx]--;
            }
            
        }
        if(check(tmp)){
            answer++;
        }
    }
    
    return answer;
}