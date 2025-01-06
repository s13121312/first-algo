#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int arr[105][105];
int tmp[105][105];
int rotate_tmp[105][105];

bool is_exploit();
int bomb_quantity();
void rotate();
bool bomb();
void print();
void gravity();

void input(){
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }

}

void pro(){
    if(m == 1){
        cout << 0;
        return;
    }
    for(int i=0;i<k;i++){
        for(int i=0;i<100;i++)bomb();
        rotate();
    }

    // while(bomb()){
    // }

    for(int i=0;i<100;i++)bomb();

    //print();
    
    cout << bomb_quantity();
}

int bomb_quantity(){
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] > 0)cnt++;
        }
    }

    return cnt;
}

bool is_exploit(){

    for(int i=0;i<n;i++){
        int cnt = 1;
        for(int j=0;j<n-1;j++){
            if(arr[j][i] == arr[j+1][i]){
                cnt++;
                if(cnt >= m){
                    return true;
                }
            }
            else{
                cnt = 1;
            }
        }
        if(cnt >= m){
            return true;
        }
        
    }
    return false;
}

void rotate(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rotate_tmp[i][j] = 0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            rotate_tmp[i][j] = arr[n-j-1][i];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = rotate_tmp[i][j];
        }
    }
    gravity();

}

void gravity(){

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j] = 0;
        }
    }


    for(int i=0;i<n;i++){
        int end_of_idx = n-1;
        for(int j=n-1;j>=0;j--){
            if(arr[j][i] != 0) tmp[end_of_idx--][i] = arr[j][i];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j] = tmp[i][j];
        }
    }
}

bool bomb(){
    bool exploded = false;
    for(int i=0;i<n;i++){
        int cnt = 1;
        int start_idx = 0;
        int end_idx = 0;
        bool chk = false;
        vector<pair<int, int> > v;
        for(int j=0;j<n-1;j++){
            if(arr[j][i] == arr[j+1][i]){
                if(chk)continue;
                cnt++;
                if(cnt >= m){
                    chk = true;
                }
            }
            else{
                end_idx = j;
                if(chk)v.push_back({start_idx, end_idx});
                start_idx = j+1;
                cnt = 1;
                chk = false;
            }
        }

        if(chk){
            end_idx = n-1;
            v.push_back({start_idx, end_idx});
        }
        
        // for(auto p : v){
        //     cout << p.first << ' ' << p.second << '\n';
             
        // }
        // cout << '\n';

        //v에 들어있는거 터뜨리기
        for(auto p : v){
            for(int z=p.first;z<=p.second;z++){
                arr[z][i] = 0;
                exploded = true;
            }
        }
        
    }
    gravity();
    return exploded;
}


void print(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    // Please write your code here.
    input();
    // bomb();
    // print();

    pro();

    return 0;
}