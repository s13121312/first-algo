#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    int res = 0;
    
    cin >> n;
    if (n == 0)
    {
        cout << res;
        return 0;
    }
    vector<int> arr(n);
    //int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    int a = round(0.15 * n);
    double sum = 0;
    // cout << "a = " << a << '\n'; //
   
    for (int i = a; i < n - a; i++)
    {
        sum += arr[i];
    }
    
    res = round(sum / (n - 2 * a));

    cout << res;
    return 0;
}