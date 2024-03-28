#include<bits/stdc++.h>
using namespace std;

int n;
 //0은바다 1은 육지 
int board[102][102];
int answer=0;


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> board[i][j];
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> board[i][j];


            for(int i=0;i<n;i++)
            {
                
            }
        }
    }


    cout << answer;
}