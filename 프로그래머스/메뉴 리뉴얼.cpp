//어려운문제

#include <string>
#include <vector>

using namespace std;

int visit[15];

// void dfs(string k, int len)
// {
//     string tmp;
//     if (tmp.size() == len)
//     {

//         return;
//     }

//     for (int i =)
// }

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    for (int k = 0; k < orders.size(); k++)
    {
        string tmp = orders[k];
        for (int i = 0; i < tmp.size() - 1; i++)
        {
            for (int j = i + 1; j < tmp.size(); j++)
            {
                tmp[i][j];
            }
        }
    }

    return answer;
}