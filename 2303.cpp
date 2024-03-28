#include <bits/stdc++.h>
using namespace std;

int arr[1002][7]; // 사람수, 정수다섯개
int n;
vector<pair<int,int>> v;
int result[1002];
void func()
{
    int big=0;
    for (int i = 0; i < n; i++)
    {
        big=0;
        for(int j=0;j<5;j++)
        {
            for(int k=j+1;k<5;k++)
            {
                for(int l =k+1;l<5;l++)
                {
                    int sum=arr[i][j]+arr[i][k]+arr[i][l];
                    int out = sum%10;
                    
                    big=max(big,out);
                }
            }
        }
        result[i]=big;
        
    }
}

int main(void)
{
    int pos=0;
    
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    func();
    int answer=0;
    for(int i=0;i<n;i++)
    {
        if(answer <=result[i])
        {
            answer=result[i];
            pos=i;
        }   
        
    }
    cout << pos+1;
    return 0;
}