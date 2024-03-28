#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";

    vector<string> tmp1;
    vector<string> tmp2;
    for(int i=0;i<goal.size();i++){
        for(int j=0;j<cards1.size();j++){
            if(goal[i]==cards1[j]){
                tmp1.push_back(goal[i]);
                break;
            }
        }

        for(int j=0;j<cards2.size();j++){
            if(goal[i]==cards2[j]){
                tmp2.push_back(goal[i]);
                break;
            }
        }
    }
    for(int i=0;i<tmp1.size();i++){
        if(tmp1[i]!=cards1[i]){
            answer="No";
            return answer;
        }
    }
    for(int i=0;i<tmp2.size();i++){
        if(tmp2[i]!=cards2[i]){
            answer="No";
            return answer;
        }
    }
    return answer;
    
}