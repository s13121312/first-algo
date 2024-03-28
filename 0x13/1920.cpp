#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;
        int st = 0;
        int en = n - 1;

        while (st <= en)
        {
            int mid = (st + en) / 2;
            if (arr[mid] < target)
            {
                st = mid + 1;
            }
            
            else if (arr[mid] > target)
            {
                en = mid - 1;
            }
            else //arr[mid] == target
            {
                cout << 1<< '\n';
                break;
            }
        }
        if(st>en)    //st > en
        {
            cout << 0 << '\n';
        }
    }


    return 0;
}