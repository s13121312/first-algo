#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;
    int l = commands.size();

    for (int i = 0; i < l; i++)
    {
        int a = commands[i][0]; // i
        int b = commands[i][1]; // j
        int c = commands[i][2]; // k

        vector<int> tmp;
        
        for (int j = a-1; j <= b-1; j++)
        {
            tmp.push_back(array[j]);
        }
        sort(tmp.begin(),tmp.end());
        answer.push_back(tmp.at(c-1));
    }

    return answer;
}
