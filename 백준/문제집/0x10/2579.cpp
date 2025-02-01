// #include<bits/stdc++.h>
// using namespace std;


// int s[305];//계단에 쓰여있는 점수
// //int d[i][j]; 현재까지 j개의 계단을 연속해서 밟고 
// //i번째계단에 올라섰을때 점수 합의 최댓값 i번째 계단은 반드시 밟음
// int d[305][3];
// int main(void){

//     int t;
//     cin >>t;
//     for(int i=1;i<=t;i++)
//     {
//         cin >>s[i];
//     }
//     if(t==1){
//         cout << s[1];//계단1개면 걍 바로끝내버리기
//         return 0;
//     }
//     d[1][1]=s[1];
//     d[1][2]=0;
//     d[2][1]=s[2];
//     d[2][2]=s[1]+s[2];
//     for(int i=2;i<=t;i++){
//         d[i][1]=max(d[i-2][1],d[i-2][2])+s[i];
//         d[i][2]=d[i-1][1]+s[i];
//     }
//     int ans =max(d[t][1],d[t][2]);
//     cout << ans;


//     return 0;
// }
// i번째 계단까지 고려했을 때 밟지 않을 계단의 합의 최솟값,
// 단 i번째 계단은 반드시 밟지 않을 계단으로 선택해야 함
#include<bits/stdc++.h>
using namespace std;

int d[305];
int s[305];

int main(void){
    int t;
    cin >>t;

    for(int i=0;i<t;)
    return 0;
}