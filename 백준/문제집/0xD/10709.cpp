#include <bits/stdc++.h>
using namespace std;

char board[102][102];
int cloud[102][102];

int main(void)
{
    int h, w; // h는 세로 w는 가로
    cin >> h >> w;
    memset(cloud,-1,sizeof(cloud));
    
    for (int i = 1; i <= h; i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin >> board[i][j];
        }
    }

    // for (int i = 1; i <= h; i++)
    // {
    //     fill(cloud[i], cloud[i] + w, -1);
    // }
    

    for (int i = 1; i <= h; i++) 
    {
        for (int j = 1; j <= w; j++)
        {
            if (board[i][j] == 'c') // c를 만나면 0으로 만들고
            {
                cloud[i][j] = 0;
            }
            else if(cloud[i][j-1]>=0)
            {
                cloud[i][j] = cloud[i][j-1] + 1;
            }
        }
    }

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cout << cloud[i][j]<<" ";
        }
        cout<< '\n';
    }

    return 0;
}