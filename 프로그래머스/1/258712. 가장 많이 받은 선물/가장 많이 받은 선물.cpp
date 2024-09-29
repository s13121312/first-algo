#include<bits/stdc++.h>

using namespace std;

//unordered_map은 pair 지원하지않음
unordered_map<string,int> tofrom;
unordered_map<string, int> give;
unordered_map<string, int> recieve;
unordered_map<string, int> res;

string create_key(string a, string b){
    return a + ":" + b;
}

//a,b 두 사람이 선물을 주고받은 기록이 있으면 true 반환
bool tiki(string a, string b){
    string tmp = create_key(a,b);
    string tmp2 = create_key(b,a);
    if(tofrom[tmp] > 0)return true;
    if(tofrom[tmp2] > 0)return true;
    return false;
}

string jisucalc(string a, string b){
    int aj = give[a] - recieve[a];
    int bj = give[b] - recieve[b];

    if(aj > bj) return a;
    else if(aj < bj)return b;
    else return "notcalculatejisu";
    //선물 지수가 같은 경우는 선물을 주고받지 않음.


}


int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;

    for(auto x : gifts){

        //!!
        stringstream ss(x);
        string a, b;
        ss >> a >> b;
        tofrom[create_key(a,b)]++;
        give[a]++;
        recieve[b]++;
    }

    //선물 지수부터 구해야함.


    for(int i=0;i<friends.size()-1;i++){
        for(int j=i+1;j<friends.size();j++){
            string key1 = create_key(friends[i],friends[j]);
            string key2 = create_key(friends[j],friends[i]);

            if(tiki(friends[i],friends[j])){
                int tmp = max(tofrom[key1], tofrom[key2]);
                if(tofrom[key1] > tofrom[key2]){
                    res[friends[i]]++;
                }else if(tofrom[key1] < tofrom[key2]){
                    res[friends[j]]++;
                }else{
                    //선물 지수가 더 큰 사람이 선물을 받음.
                    string bigone = jisucalc(friends[i], friends[j]);
                    if(bigone == "notcalculatejisu")continue;
                    else{
                        res[bigone]++;
                    }
                }
            }
            else{
                string bigone = jisucalc(friends[i], friends[j]);
                if(bigone == "notcalculatejisu")continue;
                else{
                    res[bigone]++;
                }
            }
        }
        
    }

    for(auto x : friends){
        answer = max(res[x], answer);
    }

    return answer;
}