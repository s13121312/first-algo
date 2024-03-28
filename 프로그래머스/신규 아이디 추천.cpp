#include <bits/stdc++.h>
using namespace std;

string solution(string new_id)
{
    string answer = "";

    // 1
    for (int i = 0; i < new_id.size(); i++)
    {
        if(new_id[i]>='A' && new_id[i]<='Z'){
            new_id[i] = tolower(new_id[i]);
        }
    }

    // 2
    for(int i = 0; i < new_id.length();) {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9')
              || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
            i++;
            continue;
        }
        new_id.erase(new_id.begin() + i);
    }
    // 3
    for (int i = 1; i < new_id.size();)
    {
        // TODO 두번 이상 연속된곳을 하나로
        if (new_id[i] == '.' && new_id[i-1] == '.')
        {
            new_id.erase(new_id.begin() +i);
            continue;
        }
        else i++;
    }

    // 4
    if (new_id[0] == '.')
    {
        new_id.erase(new_id.begin());
    }
    if (new_id[new_id.size() - 1] == '.')
    {
        new_id.erase(new_id.size()-1);
    }

    // 5
    if (new_id.size() == 0)
    {
        new_id = 'a';
    }

    if (new_id.size() >= 16)
    {
        while (new_id.size()!=15)
        {
            new_id.erase(new_id.begin()+15);
        }
    }
    if(new_id[new_id.size()-1]=='.'){
        new_id.erase(new_id.size()-1);
    }

    // 7
    if (new_id.size() <= 2)
    {
        while (new_id.size() != 3)
        {
            new_id += new_id[new_id.size()-1];
        }
    }
    answer = new_id;
    return answer;
}