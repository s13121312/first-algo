#include<bits/stdc++.h>
using namespace std;

char board[3100][3100];

void func(int n,int x,int y) // 
{
    if(n==3)
    {
        
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(i==0 && j==0)continue;
            if(i==1 && j==0)continue;
            if(i==3 && j==0)continue;
            if(i==4 && j==0)continue;
            if(i==0 && j==1)continue;
            if(i==2 && j==1)continue;
            if(i==4 && j==1)continue;
            func(n/2,x+n/2*i,y+n/2*j);
        }
    }
}
int main(void)
{

    int n;
    cin >> n;
    return 0;
}