//다시 풀기
#include<bits/stdc++.h>

#include <string>
#include <vector>
#include <bitset>
using namespace std;

// arr1이 지도 1 arr2가 지도2
//두 지도를 합쳐서 어느 하나라도 벽인부분은 합친지도에서도 벽
//이진수로 변환하고 맵 합치기

string translate(int a, int len){ 
    
    string result;

    for(int i=0;i<len;i++){
        result += to_string(a%2);
        a/=2;
    }

    reverse(result.begin(),result.end());
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> tmp1,tmp2;
   

    for(int i=0;i<n;i++){
        tmp1.push_back(translate(arr1[i],n));
        tmp2.push_back(translate(arr2[i],n));
    } 

    for(int i=0;i<n;i++){
        string s;
        for(int j=0;j<n;j++){
            if(tmp1[i][j]=='1' || tmp2[i][j]=='1'){
                s += '#';
            }
            else{
                s += ' ';
            }
        }
        answer.push_back(s);
    }


    return answer;
}