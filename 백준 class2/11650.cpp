// #include <bits/stdc++.h>
// using namespace std;

// int main(void)
// {

//     int n;
//     cin >> n;
//     int x[100005];
//     int y[100005];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> x[i] >> y[i];
//     }

//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = 0; j < i; j++)
//         {
//             if (x[j] > x[j + 1])
//             {
//                 swap(x[j],x[j+1]);
//                 swap(y[j],y[j+1]);
//             }
//             if(x[j] == x[j+1])
//             {
//                 if(y[j] > y[j+1])
//                 {
//                     swap(y[j],y[j+1]);
//                 }
//             }
//         }
//     }

//     for(int i=0;i<n;i++)
//     {
//         cout << x[i] <<" " << y[i] << '\n';
//     }   
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> p1, pair<int, int> p2){
    if(p1.first == p2.first){
        return p1.second < p2.second;
    }
    else{
        return p1.first < p2.first;
    }
}

int main(void)
{
    int n,x,y;
    cin >> n;
    vector<pair<int, int>> v;

    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        v.push_back(make_pair(x,y));
    }

    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n;i++)
    {
        cout << v[i].first << " " << v[i].second << '\n';
    }
    return 0;
}