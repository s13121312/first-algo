//로직이맞는데 왜틀??? 문제
#include <bits/stdc++.h>
using namespace std;

int m, n;

int solution(int m, int n, vector<string> board)
{
    int answer = 0;
    bool canRemove = true;

    while (canRemove)
    {
        bool isused[35][35] = {false, };
        canRemove = false;

        for (int i = 0; i < m - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if(board[i][j]==' ')continue;
                if (board[i][j] == board[i][j + 1] && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 1][j + 1])
                {

                    isused[i][j] = true;
                    isused[i][j + 1] = true;
                    isused[i + 1][j] = true;
                    isused[i + 1][j + 1] = true;
                    canRemove = true;
                }
            }
        }
    
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isused[i][j] == true)
                {
                    //board[i][j] = '0';
                    answer++;

                    for(int k=i-1;k>=0;k--){
                        board[k+1][j] = board[k][j];
                        board[k][j] = ' ';
                    }
                }
            }
        }
    }

    return answer;
}