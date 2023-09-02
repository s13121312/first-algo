/*#include <iostream>
using namespace std;

int main(void)
{
    int N,a[25],Y,M,Ys,Ms;
    cin >> N;
    
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<N;i++)
    {
        Y=10+10*(a[i]/30);
        M=15+15*(a[i]/60);
        Ys+=Y;
        Ms+=M;
    }

    if(Ys>Ms)
        cout<<"M "<<Ms;
    else if(Ys=Ms)
        cout<<"Y M "<<Ys;
    else
        cout<<"Y" <<Ys;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int phone[10000],Y, M;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >>N;

    for(int i=0;i<N;i++)
    {
        cin >> phone[i];
    }
    for(int i=0;i<N;i++)
    {
        Y+=((phone[i] / 30) + 1)*10;
    }
    for(int i=0;i<N;i++)
    {
        M+=((phone[i] / 60) + 1)*15;
    }
    if(Y < M) cout<<"Y " <<Y;
    else if(Y>M) cout<< "M " <<M;
    else cout<< "Y M " <<Y;
}