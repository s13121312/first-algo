#include <bits/stdc++.h>
using namespace std;

int arr[25];
int n,s;
int cnt=0;

void func(int cur, int total){
    if(cur == n)
    {
        if(total == s)
        {
            cnt++;
        }
        return;
    }
    func(cur+1,total); //cur를 더하지않았을때
    func(cur+1,total+arr[cur]); //더했을때
}

int main(void){

    cin >> n >>s;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    func(0,0);
    
    if(s==0)
    {
        cnt--;
    }
    cout << cnt;
    return 0;
}