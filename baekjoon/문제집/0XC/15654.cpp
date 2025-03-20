#include <bits/stdc++.h>
using namespace std;

int n,m; // 1<=n,m<=8
int input[10];
int arr[10];
bool isused[10005];

void func(int depth){
    if(depth==m)
    {
        for(int i=0;i<m;i++)
        {
            cout << arr[i] << ' ';
        }
        cout <<'\n';
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(!isused[input[i]])
        {
            arr[depth]=input[i];
            isused[input[i]]=1;
            func(depth+1);
            isused[input[i]]=0;
        }
        
    }

}

int main(void)
{
    cin >> n >>m;
    for(int i=0;i<n;i++)
    {
        cin >> input[i];
    }
    sort(input,input+n);

    func(0);

    return 0;
}