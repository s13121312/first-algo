//구현 X
#include<bits/stdc++.h>
using namespace std;

//제일위에거를 버리고그다음으로위에있는거를 아래로옮기고 반복

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    queue<int> q;
    int arr[1005];
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    for(int i=0;i<n;i++)
    {
        arr[i] =  q.front();
        q.pop();

        q.push(arr[i]);
    }
    
    
    

    return 0;
}