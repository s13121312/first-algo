#include <bits/stdc++.h>
using namespace std;

int arr[10];

int main(void)
{
    string input;//1,2,3,4,5,6,7,8,9
    cin >> input;
    for(int i=0;i<input.size();i++)
    {
        arr[input[i]- '0']++;
    }
    int num=0;

    for(int i=0;i<10;i++)
    {
        if(i!= 6 && i!=9 )
        {
            num = max(num, arr[i]);
        }
    }
    cout << max(num,(arr[6]+arr[9]+1)/2);



    return 0;
}