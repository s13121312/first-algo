#include<bits/stdc++.h>
using namespace std;

int match(vector<string> name, string a){
    int idx=-1;
    for(int i=0;i<name.size();i++){
        if(a==name[i]){
            idx=i;
            return idx;
        }
    }
    return idx;

}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    int sum;
    for(int i=0;i<photo.size();i++){
        sum=0;
        for(int j=0;j<photo[i].size();j++){
            if(match(name,photo[i][j])>=0){
                sum +=yearning[match(name,photo[i][j])];
            }
        }
        answer.push_back(sum);
    }
    

    return answer;
}