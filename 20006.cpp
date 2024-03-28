#include <bits/stdc++.h>
using namespace std;

unordered_map<int, string> player;

int p, m;

void func()
{
}
int main(void)
{

    vector<pair<int, string>> v;

    cin >> p >> m; // 플레이어수, 방의 정원

    int base;
    vector<int> level(305);
    vector<string> name(305);

    vector<vector<string>> room;

    for (int i = 0; i < p; i++)
    {
        cin >> level[i] >> name[i];
    }

    for (int i = 0; i < p; i++)
    {
        if (level[i] >= base - 10 && level[i] <= base + 10)
        {
            room[i].push_back(name[i]);
        
        }
        else
        {

        }
    }

    return 0;
}