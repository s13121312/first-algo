#include <string>
#include <vector>
#include<algorithm>
using namespace std;





int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i=0;i<skill_trees.size();i++){
        string tmp;
        bool check = true;
        for(int j=0;j<skill_trees[i].size();j++){
            // skill에있는 단어와 일치했을때 
            if(find(skill.begin(),skill.end(),skill_trees[i][j]) != skill.end()){
                tmp.push_back(skill_trees[i][j]);
            }
        }

        //skill 순서와 skill_trees가맞는지
        for(int j=0;j<tmp.size();j++){
            if(tmp[j] != skill[j]){
                check=false;
                break;
            }
        }
        if(check){
            answer++;
        }
    }


    return answer;
}