#include <bits/stdc++.h>
using namespace std;

int n, arr[1005];
int tmp[1005];

bool chk()
{
    // 완벽한 햄버거인지 아닌지 판별
    // 완벽하지않으면 0출력

    sort(tmp, tmp + n);
    int big = tmp[n - 1];
    int idx = 0;
    
    //기준이 계속해서 바껴줘야하는데 고정되어있음
    int r, l;
    for(int i=0;i<n;i++){
        if (arr[i] == big)
        {
            idx = i;
            r = i+1;
            l = i-1;
        }
    }

    bool ck = true;
    
    //r은 >= n일때까지, l은<=0일때까지
    if(arr[idx] >= arr[r]&& arr[idx]>= arr[l])ck = true;
    if(!ck)return false;
    while (r<n-1)
    {
        int r2 =r+1;
        if(arr[r] >= arr[r2])r++;
        else{return false;} 
    }
    while (l>0)
    {
        int l2 = l-1;
        if(arr[l] >= arr[l2])l--;
        else{return false;}
    }
    return true;
}

void pro()
{

    long sum = 0;
    if (!chk())
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        cout << sum;
    }
}

void input()
{

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        tmp[i] = arr[i];
    }
}

int main()
{

    input();
    pro();

    return 0;
}