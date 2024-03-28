#include<bits/stdc++.h>
using namespace std;

int a[505][505]={0,};

int main(void){
    //최대가 되는 경로에 있는 수의 합
    int n;//  1<=n<=500
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin >> a[i][j];
        }
    }
    int maxsum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            //왼쪽 대각선
            if(j==0){
                a[i][j]=a[i-1][j]+a[i][j];
            }
            //오른쪽 대각선
            else if(i==j){
                a[i][j]=a[i-1][j-1]+a[i][j];
            }
            else{
                a[i][j]=max(a[i-1][j-1],a[i-1][j])+a[i][j];
            }
            maxsum=max(maxsum,a[i][j]);
        }
    }

    cout << maxsum;

    return 0;
}