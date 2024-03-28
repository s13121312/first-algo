#include<bits/stdc++.h>
using namespace std;

string func(int k,int n){

    string tmp;
    for(int i=0;i<n;i++){
        tmp += to_string(k%2);
        k/=2;
    }
    
    reverse(tmp.begin(),tmp.end());
    return tmp;

}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n+1);
    
    vector<string> tmp1;
    vector<string> tmp2;

    for(int i=0;i<n;i++){
        tmp1.push_back(func(arr1[i],n));
    }

    for(int i=0;i<n;i++){
        tmp2.push_back(func(arr2[i],n));
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