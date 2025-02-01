#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    char room[105][105];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> room[i][j];
        }
    }
    int garo = 0;
    int sero = 0;
    int row_cnt=0;
    int col_cnt=0;
    for(int i=0;i<n;i++)
    {
        row_cnt=0;//다른 라인으로 넘어갈때 초기화해줘야함
        for(int j=0;j<n;j++)
        {
            
            if(room[i][j]=='.')
            {
                row_cnt++;
            }   
            else{ // X
                row_cnt=0;
            }

            if(row_cnt==2)
            {
                garo++;
            }
        }
    }    

    for(int i=0;i<n;i++)
    {
        col_cnt=0;
        for(int j=0;j<n;j++)
        {
            if(room[j][i]=='.')
            {
                col_cnt++;
            }   
            else{ // X
                col_cnt=0;
            }

            if(col_cnt==2) // 굳이 >=로 처리하지않는게 포인트 ..X..같은 걸 세기위해
            {
                sero++;
            }
        }
    }  
    cout << garo << " " << sero;

    return 0;
}