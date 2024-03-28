#include <bits/stdc++.h>
using namespace std;

string cookie[1005];

int main(void)
{
    int n;
    cin >> n;
    pair<int,int> heart;
    for (int i = 1; i <= n; i++)
    {
        cin >> cookie[i];
    }
    // 상하 좌우 가 *라면 심장이다
    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 2; j <= n - 1; j++)
        {
            if (cookie[i][j - 1] == '*' && cookie[i][j + 1] == '*' && cookie[i-1][j] == '*' && cookie[i+1][j] == '*')
            {
                heart = {i,j};
                break;
            }
        }
    }
    int left_arm=0;
    //왼쪽 팔
    for(int j=heart.second-1;j>=0;j--){
        if(cookie[heart.first][j] == '*'){
            left_arm++;
        }else{
            break;
        }
    }
    //오른쪽팔
    int right_arm=0;
    for(int j=heart.second+1;j<=n-1;j++){
        if(cookie[heart.first][j] == '*'){
            right_arm++;
        }else{
            break;
        }
    }
    //허리
    int heouri=0;
    for(int i=heart.first+1;i<=n-1;i++){
        if(cookie[i][heart.second] == '*'){
            heouri++;
        }else{
            break;
        }
    }
    //왼쪽다리
    int left_leg=0;
    for(int i=heart.first+heouri+1;i<=n;i++){
        if(cookie[i][heart.second-1] == '*'){
            left_leg++;
        }else{
            break;
        }
    }

    //오른쪽다리
    int right_leg=0;
    for(int i=heart.first+heouri+1;i<=n;i++){
        if(cookie[i][heart.second+1] == '*'){
            right_leg++;
        }else{
            break;
        }
    }

//string 으로 받아서 x좌표는 +1해서 출력해줌
    cout << heart.first << ' '<<heart.second+1 << '\n';
    cout << left_arm <<' ' << right_arm << ' ' << heouri << ' ' << left_leg << ' ' << right_leg<<'\n';

}