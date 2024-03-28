#include <bits/stdc++.h>
using namespace std;

string WB[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
}; 

string BW[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
}; 

string board[50];

int w_start(int x, int y){ //w로 시작할때 카운트값
    int count = 0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[x+i][y+j] != WB[i][j])
                count++;
        }
    }

    return count;
}

int b_start(int x, int y){
    int count = 0;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[x+i][y+j] != BW[i][j])
                count++;
        }
    }
    return count;
}

int main(void)
{
    int m, n;
    cin >> m >> n;

    int min_val = 12345;
    
    for(int i=0;i<m;i++)
    {
        cin >> board[i];
    }

    for(int i=0;i+8<=m;i++)
    {
        for(int j=0;j+8<=n;j++)
        {
            int tmp = min(b_start(i,j),w_start(i,j));
            if(tmp < min_val)
            {
                min_val = tmp;
            }
        }
    }

    cout << min_val<<'\n';

    return 0;
}