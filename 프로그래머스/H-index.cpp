#include <string>
#include <vector>
#include<algorithm>

using namespace std;

bool cmp(int &a, int &b){
    return a>b;
}
int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),cmp);
    if(citations[0]==0)return 0;
    for(int i = 0; i <citations.size();i++){
        if(citations[i] >= i+1){ //i+1이 자기 이상인 논문개수다
            answer= i+1;
        }
    }
    return answer;
}

