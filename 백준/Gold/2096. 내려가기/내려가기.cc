#include<bits/stdc++.h>
using namespace std;

/*int n;
int arr[100000][4];
int dpmax[100000][4] = {0, };
int dpmin[100000][4]{0, };
*/
void sol();

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin >> arr[i][j];
        }
        
    }

    dpmax[1][1] = arr[1][1];
    dpmax[1][2] = arr[1][2];
    dpmax[1][3] = arr[1][3];
    dpmin[1][1] = arr[1][1];
    dpmin[1][2] = arr[1][2];
    dpmin[1][3] = arr[1][3];
    int bigans = -9999999;
    int smallans = 9999999;


    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            if(j==1){
                dpmax[i][j] = arr[i][j] + max(dpmax[i-1][j], dpmax[i-1][j+1]);
                dpmin[i][j] = arr[i][j] + min(dpmin[i-1][j], dpmin[i-1][j+1]);
            }
            if(j==2){
                dpmax[i][j] = arr[i][j] + max(dpmax[i-1][j-1], max(dpmax[i-1][j], dpmax[i-1][j+1]));
                dpmin[i][j] = arr[i][j] + min(dpmax[i-1][j-1], min(dpmax[i-1][j], dpmax[i-1][j+1]));

            }
            if(j==3){
                dpmax[i][j] = arr[i][j] + max(dpmax[i-1][j], dpmax[i-1][j-1]);
                dpmin[i][j] = arr[i][j] + min(dpmin[i-1][j], dpmin[i-1][j-1]);
            }
        }
    }

    for(int i=1;i<=3;i++){
        bigans = max(bigans, dpmax[n][i]);
        smallans = min(smallans, dpmin[n][i]);
    }

    cout << bigans << ' ' << smallans;
    */
   //위방식은 메모리 초과발생.


    sol();

    return 0;
}

void sol(){
    int n;
    int maxv, minv;
    int minarr[3] = {0,};
    int maxarr[3] = {0,};
    int input[3] = {0,};


    cin >> n;

    cin >> maxarr[0] >> maxarr[1] >> maxarr[2];
    minarr[0] = maxarr[0];
    minarr[1] = maxarr[1];
    minarr[2] = maxarr[2];

    //위에서 한번 받았으니까
    for(int i=1;i<n;i++){
        cin >> input[0] >> input[1] >> input[2];

        int tmp0 = maxarr[0];
        int tmp1 = maxarr[1];
        int tmp2 = maxarr[2];

        maxarr[0] = max(tmp0, tmp1) + input[0];
        maxarr[1] = max(tmp2, max(tmp0, tmp1)) + input[1];
        maxarr[2] = max(tmp1, tmp2) + input[2];

        tmp0 = minarr[0];
        tmp1 = minarr[1];
        tmp2 = minarr[2];

        minarr[0] = min(tmp0, tmp1) + input[0];
        minarr[1] = min(tmp2, min(tmp0, tmp1)) + input[1];
        minarr[2] = min(tmp1, tmp2) + input[2];
    }

    maxv = max(maxarr[0], max(maxarr[1],maxarr[2]));
    minv = min(minarr[0], min(minarr[1], minarr[2]));

    cout << maxv << ' ' << minv;

}