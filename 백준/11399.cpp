// 걸리는 시간이 적은 사람을 앞에 배치

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int arr[1005];
    int order[1005];

    int k = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        arr[i + 1] += arr[i];
        
        sum += arr[i];               
    }
    /*
    for(int i=0;i<n;i++)
    {
        sum += arr[i]*(n-i);
    }
    */
    cout << sum;
    return 0;
}