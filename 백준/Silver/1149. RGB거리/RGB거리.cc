#include<bits/stdc++.h>
using namespace std;

int n;
int Ay[1005][3];
int Dy[1005][3];

void input(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            cin >> Ay[i][j];
        }
    }

}

void pro(){

    Dy[2][0] = Ay[2][0] + min(Ay[1][1], Ay[1][2]);
    Dy[2][1] = Ay[2][1] + min(Ay[1][0], Ay[1][2]);
    Dy[2][2] = Ay[2][2] + min(Ay[1][0], Ay[1][1]);

    for(int i=3;i<=n;i++){
        Dy[i][0] = Ay[i][0] + min(Dy[i-1][1],Dy[i-1][2]); 
        Dy[i][1] = Ay[i][1] + min(Dy[i-1][0],Dy[i-1][2]); 
        Dy[i][2] = Ay[i][2] + min(Dy[i-1][0],Dy[i-1][1]); 
    }

    cout << min(Dy[n][0],min(Dy[n][1],Dy[n][2]));
}
int main(){
    input();
    pro();

    return 0;
}