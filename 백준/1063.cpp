//이게 xy 방향 설정 라는게 정신나감

#include <bits/stdc++.h>
using namespace std;

int arr[10][10];
int m;
bool check(int x, int y);
bool rock_chk(int x, int y);
pair<int, int> k_p;
pair<int, int> r_p;
// r, l, b, t, rt, lt, rb, lb
int dx[10] = {0, 0, -1, -1, -1, -1, 1, 1};
int dy[10] = {1, -1, 0, 0, 1, -1, 1, -1};
int main(void)
{

    string king_pos, rock_pos;
    cin >> king_pos >> rock_pos >> m;

    k_p = {8-(king_pos[1]-'0'), king_pos[0] - 'A'};
    r_p = {8 - (rock_pos[1]-'0'), rock_pos[0] - 'A'}; 

    int index = 0;

    for (int i = 0; i < m; i++)
    {
        string input;
        cin >> input;

        if (input == "R")
        {
            index = 0;
        }
        if (input == "L")
        {
            index = 1;
        }
        if (input == "B")
        {
            index = 2;
        }
        if (input == "T")
        {
            index = 3;
        }
        if (input == "RT")
        {
            index = 4;
        }
        if (input == "LT")
        {
            index = 5;
        }
        if (input == "RB")
        {
            index = 6;
        }
        if (input == "LB")
        {
            index = 7;
        }
        int nx = k_p.first + dx[index];
        int ny = k_p.second + dy[index];
        if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
            continue;

        if (nx == r_p.first && ny == r_p.second)
        {
            int nnx = r_p.first + dx[index];
            int nny = r_p.second + dy[index];

            if (nnx < 0 || nnx >= 8 || nny < 0 || nny >= 8)
                continue;
            else{
                r_p = {nnx, nny};
            }
        }
        k_p = {nx, ny};
    }
    cout << (char)(k_p.first + 'A') << k_p.second << '\n';
    cout << (char)(r_p.first + 'A') << r_p.second << '\n';
    return 0;
}

bool check(int x, int y)
{
    if (x < 0 || x >= 8 || y < 0 || y >= 8)
        return false;
    return true;
}
