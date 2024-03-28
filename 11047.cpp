#include<bits/stdc++.h>
using namespace std;

int sum;
int cnt;
int main(void)
{

    int n,k;
    cin >> n >> k;
    int money[12];
    int dongjun;
    for(int i=0;i<n;i++)
    {
        cin >> dongjun;
        money[i]=dongjun;
    }
    int temp_cnt=0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum +=money[i];
            temp_cnt++;
            if(sum==k)
            {
                cnt = min(temp_cnt,cnt);
            }
        }
    }
    

    return 0;
}