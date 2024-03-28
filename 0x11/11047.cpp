/*#include<bits/stdc++.h>
using namespace std;

//int d[1000000005]; //k원을 만드는데 필요한 동전 개수 최소값
int a[15];

int main(void){

    int n,k;
    cin >> n >> k;
    vector<int> d(k+1);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    fill(d.begin(),d.end(),k+1);
    d[0]=0;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=k;j++){
            d[j]= min(d[j], d[j-a[i]]+1);
        }
    }

    cout << d[k];
    return 0;
}
    n*k라서 시간초과남
*/

#include <bits/stdc++.h>
using namespace std;

int a[15];
int main(void)
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (k / a[i] > 0){
            ans += k/a[i];
            k -= (k/a[i])*a[i];
        }   
    }

    cout << ans;
    return 0;
}