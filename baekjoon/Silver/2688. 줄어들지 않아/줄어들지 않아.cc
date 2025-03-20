#include<bits/stdc++.h>
using namespace std;

int n;
long long Dy[65][10];
//길이 n일때 last가끝의원소인 것의 개수
//Dy[i][last]
long long pro(int tmp);

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >>tmp;
        cout << pro(tmp) << '\n';
    }
}

long long pro(int tmp){

    for(int i=1;i<=tmp;i++){
        for(int j=0;j<=9;j++){
            Dy[i][j] = 0;
        }
    }

    for(int i=0;i<=9;i++){
        Dy[1][i] = 1;
    }

    for(int i=2;i<=tmp;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=j;k++){
                Dy[i][j] += Dy[i-1][k];
            }
        }
    }
    long long sum = 0;
    for(int i=0;i<=9;i++){
        sum += Dy[tmp][i];
    }

    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();

    return 0;
}