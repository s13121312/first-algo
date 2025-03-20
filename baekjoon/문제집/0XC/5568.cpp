#include <bits/stdc++.h>
using namespace std;

int n, k;
int ans = 0;
bool isused[15];
vector<string> r(5050);

unordered_map<int, int> m;
vector<int> v1;
void func(int depth, string result)
{
    if (depth == k)
    {
        bool check = true;
        for(int i=0;i<r.size();i++){
            if(r[i] == result){
                check =false;
                break;
            }
        }
        if(check){
            ans++;
            r.push_back(result);
        }
        return;
    }

    //순열
    for (int i = 0; i < n; i++)
    {
        if(isused[i])continue;
        isused[i]=true;    
        func(depth + 1, result + to_string(v1[i]));
        isused[i]=false;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        v1.push_back(inp);
    }

    func(0, "");

    cout << ans;
    return 0;
}