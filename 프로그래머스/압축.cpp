#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;


    unordered_map<string, int> dict; // 단어,색인 번호

    int x;
    string s = "";
    for (x = 1; x <= 26; x++){
        s += 'A' + x - 1;
        dict[s]=x;
        s = "";
    }

    
    for (int i = 0; i < msg.size(); i++)
    {
        string tmp;
        tmp += msg[i];
        int j=i;
        int count =0;

        // while (dict.find(tmp) != dict.end())
        // {
        //     count++;
        //     j++;
        //     tmp += msg[j];
        // }
        
        // i += count -1;
         dict[tmp]= x++;
        // tmp.pop_back();
        // answer.push_back(dict[tmp]);

        while (dict.find(tmp)!= dict.end())
        {
            j++;
            tmp += msg[j]; 
        }

        
        for (int j = i; j < msg.size(); j++)
        {
            tmp += msg[j];
            if (dict.find(tmp) != dict.end()) //찾는게있다? -> 다음문자로넘어가기
            {
                continue; //여기가 잘못된듯?
            }
            if (dict.find(tmp) == dict.end()) //찾는게 없다? -> 사전에 넣기
            {
                dict[tmp] = x + 1;
                x++;
                answer.push_back(dict[tmp.substr(0,tmp.size()-1)]);
                i += tmp.size()-2; //문자열 다음 문자로 넘어가기 위해서
                break;
            }
        }
    }

    return answer;
}