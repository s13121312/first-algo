// #include <bits/stdc++.h>
// using namespace std;

// void sot(string arr[20005], int n);

// int main(void)
// {

//     int n;
//     cin >> n;

//     string arr[20005];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     sot(arr, n);
//     return 0;
// }

// void sot(string arr[20005], int n)
// {
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (arr[j].length() > arr[j + 1].length())
//             {
//                 swap(arr[j], arr[j + 1]);
//             }
//             if (arr[j].length() == arr[j + 1].length() && arr[j] > arr[j + 1])
//             {
//                 swap(arr[j],arr[j+1]);
//             }

//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         if(arr[i]==arr[i-1]){ // 같은단어면 한번만 출력
//             continue;
//         }
//         cout << arr[i] << '\n';
//     }

// }

#include <bits/stdc++.h>
using namespace std;

int compare(string a, string b)
{
    if(a.length() == b.length()){
        return a<b;
    }
    else{
        return a.length()<b.length();
    }
}
int main(void)
{
    int n;
    cin >> n;

    string arr[20005];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n, compare);

    for (int i = 0; i < n; i++)
    {
        if(arr[i]==arr[i-1]){
            continue;
        }
        cout << arr[i]<<'\n';
    }
    return 0;
}