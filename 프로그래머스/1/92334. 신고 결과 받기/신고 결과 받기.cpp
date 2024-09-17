#include<bits/stdc++.h>
using namespace std;


//https://myprivatestudy.tistory.com/48
//블로그에 글써야겠다. 맨날 헷갈려해서.문자열나누는거

vector<vector<string>> chk; //a가b를신고했을때 신고했다는표시를남김.
unordered_map<string, int> um;
vector<int> answer;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    
    chk.resize(id_list.size());
    answer.resize(id_list.size());
    for(auto x : report){
        string a, b;
        stringstream ss(x); //공백기준으로 문자열을 나눌수있음
        ss >> a >> b;
        int idx = find(id_list.begin(),id_list.end(), a) - id_list.begin();
        
         

        if(find(chk[idx].begin(),chk[idx].end(), b) == chk[idx].end()){
            chk[idx].push_back(b); //id_list의 idx번째 유저는 b를 신고했음
            um[b]++;
        }

    }


    vector<string> stopmem;

    //위에서 신고한거처리했고 이제정지된애들은(id_list에들어있음)
    for(auto x : id_list){
        if(um[x] >= k){ //정지될애들임.
            stopmem.push_back(x);
        }
    }

    //정지된애들을 신고한 사람의(chk에 들어있음) answer를 증가시켜줘야함메일을 보내줘야하기에

    for(int i=0;i<chk.size();i++){
        for(auto x: stopmem){ //정지된 사람들중 그사람을신고한 사람은 answer을 증가시켜줌
            if(find(chk[i].begin(),chk[i].end(), x) != chk[i].end())answer[i]++;
        //근데 idx가 맞나? 신고한사람 인덱스랑 일치하나?

        }
    }


    return answer;
}