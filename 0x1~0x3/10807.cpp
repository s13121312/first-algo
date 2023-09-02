#include <bits/stdc++.h>
using namespace std;

/*int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, arr[101],v,cnt=0;
    cin >> N;
    for(int j=0;j<N;j++)
    {
        cin >> arr[j];
    }
    cin >> v;
    for(int i=0;i<N;i++)
    {
        if(arr[i]==v)
            cnt++;
    }
    cout << cnt;
    return 0;
}음수를 처리못할듯*/

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,arr[201] = {}, v; //-100<=v<=100이므로 음수도 처리할수있게
    cin >> N;

    while(N--)
    {
        int t;
        cin >> t;
        arr[t+100]++;
    }
    cin >> v;
    cout <<arr[v+100];
}