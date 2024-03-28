#include <bits/stdc++.h>
using namespace std;

string solution(vector<int> numbers, string hand)
{
    string answer = {};
    vector<pair<int,int>> loc = { {0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2},{3,0},{3,1},{3,2} };

    pair<int,int> leftloc = {3,0};
    pair<int,int> rightloc = {3,2};

    int leftabs=0;
    int rightabs=0;

    for (int i = 0; i < numbers.size(); i++)
    {
        if(numbers[i]==0){
            numbers[i] = 11;
        }
        if (numbers[i] % 3 ==1)
        {
            // 왼손쓰기
            answer += 'L';
            leftloc = loc[numbers[i]-1];
        }
        else if (numbers[i] % 3 ==0)
        {
            // 오른손쓰기
            answer += 'R';
            rightloc = loc[numbers[i]-1]; 
        }
        else
        {
            leftabs = abs(leftloc.first- loc[numbers[i]-1].first) + abs(leftloc.second-loc[numbers[i]-1].second);
            rightabs = abs(rightloc.first- loc[numbers[i]-1].first) + abs(rightloc.second-loc[numbers[i]-1].second);            
            
            if (leftabs > rightabs)
            {
                // 오른쪽이누르기
                answer += 'R';
                rightloc = loc[numbers[i]-1];
                
            } 
            else if (leftabs==rightabs)
            {
                if (hand == "right")
                {
                    rightloc = loc[numbers[i]-1];
                    answer += 'R';
                }
                else
                {
                    leftloc = loc[numbers[i]-1];
                    answer += 'L';
                }
            }
            
            // 거리작은놈이 누르기
            else
            {
                leftloc = loc[numbers[i]-1];
                answer += 'L';
            }
        }
    }
    return answer;
}


