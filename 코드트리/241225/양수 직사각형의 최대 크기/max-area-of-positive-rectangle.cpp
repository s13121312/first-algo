#include <bits/stdc++.h>
using namespace std;

int ans = -1;
int n,m;
int arr[25][25];


void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
}
bool out_range(int x, int y){
    return (x<0 || x>=n || y<0 || y>=m);
}

int find_rectangle(int x, int y, int w, int h){
    int sum = 0;

    for(int i=x;i<x+h;i++){
        for(int j=y;j<y+w;j++){
            if(out_range(i,j))return -1;
            if(arr[i][j] <= 0)return -1; //이미 나가리 확정
            sum++; 
        }
    }
    //cout << "find_rectangle결과: " << sum << ", x: " << x << ", y: " << y << ", w,h:" <<w << ' ' << h << '\n';
    return sum;
}

void pro(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int h=1;h<=n;h++){
                for(int w=1;w<=m;w++){
                    int tmp = find_rectangle(i, j, w, h);
                    if(tmp != -1){
                        ans = max(ans, tmp);
                    }
                    
                }
            }
        }
    }

    cout << ans;
}

int main() {
    // 여기에 코드를 작성해주세요.
    input();
    pro();


    return 0;
}