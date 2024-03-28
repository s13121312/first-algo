#include<bits/stdc++.h>
using namespace std;

int n,m;
int arr[10]; //들어갈 배열
bool isused[10]; //쓰였는지확인하는

void func(int st, int depth){
    if(depth == m)
    {
        for(int i=0;i<m;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    
    for(int i=st;i<n;i++)
    {
        if(!isused[i])
        {
            arr[depth] = i;
            isused[i]=true;
            func(i+1, depth+1);
            isused[i]=false;
        }
    }
}
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n >>m;
    func(1, 0);
    return 0;
}

// int arr[10];
// bool visit[10];
// int n,m;
// void func(int k);

// int main(void)
// {
//     cin >> n>>m;
//     func(0);
// }
// void func(int k)
// {
//     if(k==m)
//     {
//         for(int i=0;i<m;i++)
//         {
//             cout << arr[i]<< " ";
//         }
//         cout << '\n';
//         return;
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(!visit[i])
//         {
//             arr[k]=i;
//             visit[i]=true;
//             func(k+1);
//             visit[i]=false;
//         }
//     }
// }