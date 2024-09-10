#include<bits/stdc++.h>
#include<vector>
using namespace std;



int n, m;
int arr[1005];
int water[1005];
int s[100005];
int e[100005];

//bool chk[1005]; 이러면 언제 비가내렸는지 체크를 못함

int rainy_day[1005];

void pluswater(int s, int e, int day)
{
    for (int i = s; i <= e; i++)
    {
        water[i]++;
        rainy_day[i] = day;
    }
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= m; i++)
    {
        cin >> s[i] >> e[i]; // s~e까지 비가옴. 그집의 물의 높이 1증가.
        pluswater(s[i], e[i], i);
        if (i % 3 == 0)
        {
            // TODO 비가 내린 위치도 체크를 해줘야함.2일이내에 비가내린곳
            for (int j = 1; j <= n; j++)
            {
                if (i - rainy_day[j] <= 2)
                {
                    water[j]--;
                }
            }
        }
    }
}

void pro()
{

    // 3,6,9.. 3의 배수가되는날마다 배수시스템 작동.
    // 3일이면은 321 이렇게 2일 이내로만 물의 높이가 1 감소.
    // 땅높이는 쌓인 물 높이만큼 증가.

    for (int i = 1; i <= n; i++)
    {
        arr[i] += water[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
}

int main()
{

    input();
    pro();

    return 0;
}