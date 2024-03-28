#include <string>
#include<vector>
#include<algorithm>

using namespace std;

int solution(string dartResult) {
    int answer = 0;

    string num = ""; // 포인트!
    int idx = 0;
    vector<int> result;
    for(int i=0;i<dartResult.size();i++){
        if(dartResult[i] >= '0' && dartResult[i] <= '9') num += dartResult[i];
        
        else if(dartResult[i] =='S'){
            result.push_back(stoi(num));
            num="";
            idx++;
        }
        else if(dartResult[i] == 'D'){
            result.push_back(stoi(num)*stoi(num));
            num="";
            idx++;
        }
        else if(dartResult[i] == 'T'){
            result.push_back(stoi(num)*stoi(num)*stoi(num));
            num="";
            idx++;
        }
        else if(dartResult[i] == '*'){
            result[idx-1] *= 2; // idx가 아닌 idx-1인 이유가  S,D,T에서 idx에서 추가되었기에
            if(idx>=2){ 
                result[idx-2] *= 2;
            }
        }
        else if(dartResult[i] == '#'){
            result[idx-1] *= -1;
        }
    }

    for(int i=0;i<3;i++){
        answer += result[i];
    }

    return answer;
}