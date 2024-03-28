#include <bits/stdc++.h>
using namespace std;

int arr[8];
int n,m;

void func(int cur){
    if(cur == m)
    {
        for(int i=0;i<m;i++)
        {
            cout << arr[i]<< " ";
        }
        cout <<'\n';
        return;
    }
    int st =1; // cur=0일때
    if(cur != 0) st=arr[cur-1]; //"최소 시작점",바로앞의거보다는 크게
    for(int i=st;i<=n;i++) //숫자 넣기 시작
    {
        arr[cur]=i;
        func(cur+1);        
    }

}

int main(void)
{
    cin >> n >> m;
    func(0);

    return 0;
}