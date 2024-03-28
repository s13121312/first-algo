#include<bits/stdc++.h>
using namespace std;

// 대각선에서 2n-1칸이 필요하기 때문에 배열 크기는 2n-1 이상으로 둬야하는데
// 그냥 넉넉하게 40으로 둠
bool isused1[60];//열 y
bool isused3[60];//윗 대각선 x+y
bool isused2[60];//아래 대각선 

int n;
int cnt =0;
//cur는 현재 행을 나타냄
void nqueen(int cur){ //가로,세로,대각선은 못감    
    if(cur == n)
    {
        cnt++;
        return;
    }
    
    for(int i=0;i<n;i++)
    {
        if(isused1[i] || isused2[cur + i] || isused3[cur-i+n-1])
            continue;
        isused1[i]=1;
        isused2[cur + i] = 1;
        isused3[cur-i+n-1] = 1;
        nqueen(cur+1);
        isused1[i] = 0;
        isused2[cur + i] = 0;
        isused3[cur-i+n-1] = 0;
    }
   

}

int main(void)
{
    cin >>n;
    nqueen(0);
    cout << cnt;
    return 0;
}