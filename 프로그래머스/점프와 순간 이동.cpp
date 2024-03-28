#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int solution(int n)
{
    //n까지 가려고할때 최소의 경우의수
    //1움직이는건 돈 1들고 두배움직이는건 돈 안듬
    //k만큼움직이면 돈k듬

    int ans = 1;//0에서 1가는값
    while (n > 1)
    {
        if(n%2==1){
            ans++;
        }
        n /= 2;
    }

    return ans;
}