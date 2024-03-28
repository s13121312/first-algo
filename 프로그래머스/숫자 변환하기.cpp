#include <string>
#include <vector>
#include<queue>
using namespace std;

int isused[1000005];

int solution(int x, int y, int n) {
    int answer = 0;
    fill(isused+1,isused+y+1,-1);
    isused[x]=0;
    queue<int> q;
    q.push(x);
    bool check = false;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int k : {cur+n,cur*2,cur*3}){
            if(k<0 || k>=1000001) continue;
            if(isused[k] != -1)continue;
            
            isused[k]= isused[cur] + 1;
            q.push(k);
            if(k >= y)
            {
                check = true;
                break;
            }
        }
        if(check)break;
    }

    answer = isused[y];
    
    return answer;
}