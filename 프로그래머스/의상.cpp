#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes)
{
    int answer = 0;

    unordered_map<string, string> m;
    vector<pair<string, string>> p;
    for (int i = 0; i < clothes.size(); i++)
    {
        m[clothes[i][0]] = clothes[i][1];
    }
    answer += m.size(); //1개만 입는거
    vector<string> tmp; 
    for (int i = 0; i < clothes.size()-1; i++)
    {       
        tmp.push_back(m[clothes[i][0]]);
        for (int j = i + 1; j < clothes.size(); j++){
            
            for (int k = 0; k < tmp.size(); k++)
            {
                // 의상 종류가 같으면
                if(tmp[k] == m[clothes[j][0]])
                {
                    continue;
                }
                else
                {
                    answer++;
                    tmp.push_back(m[clothes[j][0]]);
                    break;
                }
            }
        }
    }
    return answer;
}
