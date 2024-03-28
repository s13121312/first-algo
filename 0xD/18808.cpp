#include<bits/stdc++.h>
using namespace std;

int note[45][45];
int paper[12][12];
int n,m,k;
int r,c;


//스티커를 90도회전하는함수
void rotate(){
    int tmp[12][12];

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            tmp[i][j]=paper[i][j];
        }
    }

    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            paper[i][j] = tmp[r-1-j][i];
        }
    }
    swap(r,c);
}


//스티커를 붙일수있는지확인하는함수
//모눈종이에 스티커가 붙은곳과 노트북의 시잠점이 겹치면 false 반환
bool pastable(int x, int y){
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(note[x+i][y+j]==1 && paper[i][j]==1) 
                return false;
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(paper[i][j]==1)
            {
                note[x+i][y+j]=1;
            }
        }
    }
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n>> m >> k;
    while(k--)
    {
        cin >> r>> c;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin >> paper[i][j];
            }
        }
        for(int rot=0;rot<4;rot++)
        {
            bool is_paste = false;
            for(int x=0;x<=n-r;x++)
            {
                if(is_paste)break;
                for(int y=0;y<=m-c;y++)
                {
                    if(pastable(x,y))
                    {
                        is_paste=true;
                        break;
                    }
                }
            }
            if(is_paste) break;
            rotate();
        }
    }


    int answer=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            answer += note[i][j];
        }
    }
    cout << answer;
    return 0;
}