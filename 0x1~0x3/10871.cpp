/*#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x,a[10004];
    cin>>n>>x;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]<x)
            cout<< a[i]<<' ';
    }
    return 0;
}*/

/*#include <iostream>
using namespace std;
int main(void)
{
    std::ios::sync_with_stdio(false);
    std:cin.tie(nullptr);
    int n,x;
    cin >> n >> x;
    int *a=new int[n];
    for(int i=0;i<n;i++)
    {
            cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]<x)
            cout<<a[i]<<' ';
    }
    delete[] a;
}
*/
#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x,t;
    cin >> n >> x;
    while(n--)
    {
        cin >>t;
        if(t<x)
            cout<<t<<' ';
    }
    return 0;
}