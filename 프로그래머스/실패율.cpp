#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, double> &a, const pair<int, double> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second > b.second; // 실패율 내림차순으로
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> answer;
    vector<int> tmp1(N+1,0);        // 실패율 분자
    vector<int> tmp2(N+1,0);        // 실패율 분모
    vector<double> failrate(N+1,0); // 실패율
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < stages.size(); j++)
        {
            if (stages[j] > i + 1)
            {
                tmp2[i]++;
            }
            if (stages[j] == i + 1)
            {
                tmp1[i]++;
                tmp2[i]++;
            }
        }
        //분모가 0일때 방지
        if(tmp2[i]==0){
            failrate[i]=0;
        }
        else{
            failrate[i] = tmp1[i] / (double)tmp2[i];
        }
    }


    vector<pair<int, double>> arr;
    for (int i = 0; i < N; i++)
    {
        arr.push_back({i+1,failrate[i]});
    }

    // TODO 정렬 해줘야함

    sort(arr.begin(), arr.end(), cmp);

    for(int i=0;i<N;i++){
        answer.push_back(arr[i].first);
    }

    return answer;
}