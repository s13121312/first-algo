#include <bits/stdc++.h>
using namespace std;

bool rule5(string a)
{
    if (a.length() == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

vector<int> solution(int n, vector<string> words)
{
    vector<int> answer;
    int num = 0;
    int pos = 0;
    
    //한 글자인 단어는 인정되지않음
    for (int i = 0; i < words.size(); i++)
    {
        if (!rule5(words[i]))
        {
            num = (i % n) + 1;
            pos = (i / n) + 1;
            answer.push_back(num);
            answer.push_back(pos);
            return answer;
        }
    }
    vector<string> tmp;
    
    // rule 4
    for(int i=0;i<words.size();i++){
        //해당 원소가 존재하지않을때
        if(find(tmp.begin(),tmp.end(),words[i])==tmp.end()){
            tmp.push_back(words[i]);
        }
        //존재할 때
        else{ 
            num = (i % n) + 1;
                pos = (i / n) + 1;
                answer.push_back(num);
                answer.push_back(pos);
                return answer;
        }
    }
    for (int i = 0; i < words.size() - 1; i++)
    {
        // rule 3
        if (words[i][words[i].size() - 1] != words[i + 1][0])
        {
            num = ((i + 1) % n) + 1;
            pos = ((i + 1) / n) + 1;
            answer.push_back(num);
            answer.push_back(pos);
            return answer;
        }        
    }
    

    if (num == 0 && pos == 0)
    {
        answer.push_back(num);
        answer.push_back(pos);
    }
    return answer;
}