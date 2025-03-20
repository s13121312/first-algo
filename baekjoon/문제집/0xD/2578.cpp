#include <bits/stdc++.h>
using namespace std;

int m[5][5];
int isused[5][5];

// 가로,세로,대각선 3개이상체크
bool check1()
{
    int ret = 0;
    for (int i = 0; i < 5; i++)
    {
        if (isused[i][0] && isused[i][1] && isused[i][2] && isused[i][3] && isused[i][4])
        {
            ret++;
        }
    }
    return ret;
}
bool check2()
{
    int ret = 0;
    for (int i = 0; i < 5; i++)
    {
        if (isused[0][i] && isused[1][i] && isused[2][i] && isused[3][i] && isused[4][i])
        {
            ret++;
        }
    }
    return ret;
}
bool check3()
{
    int ret = 0;
    for (int i = 0; i < 5; i++)
    {
        if (isused[0][0] && isused[1][1] && isused[2][2] && isused[3][3] && isused[4][4])
        {
            ret++;
        }
    }
    return ret;
}
bool check4()
{
    int ret = 0;

    if (isused[4][0] && isused[3][1] && isused[2][2] && isused[1][3] && isused[0][4])
    {
        ret++;
    }

    return ret;
}
int main(void)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> m[i][j];
        }
    }
    
    for (int answer = 0; answer < 25; answer++)
    {
        int a;
        cin >> a;
        
        int bingo_cnt = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if(m[i][j]==a)
                {
                    isused[i][j]=1;
                }
            }
        }

        bingo_cnt+=check1();
        bingo_cnt+=check2();
        bingo_cnt+=check3();
        bingo_cnt+=check4();

        if(bingo_cnt>=3){
            cout << answer+1;
            return 0;
        }
    }

    return 0;
}