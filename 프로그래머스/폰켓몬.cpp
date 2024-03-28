#include <vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int len = nums.size()/2;

    map<int, int> p;
    for(int i=0;i<nums.size();i++){
        p[nums[i]]++;
    }

    if(p.size() < len){
        answer=p.size();
    }
    if(p.size() >= len){
        answer = len;
    }


    return answer;
}