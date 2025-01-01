#include <bits/stdc++.h>
using namespace std;

int n,m;
int arr[105];
int copy_arr[105];
void print();

void input(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}

int explotion(){
    int tmp = arr[0];
    int cnt = 1;
    int start_pos = 0;
    int end_pos = 0;
    bool chk = false;
    vector<pair<int,int>> v;

    for(int i=1;i<n;i++){
        if(tmp == arr[i]){
            cnt++;
            end_pos++;
            if(chk)continue;
            if(cnt>=m)chk = true;
        }
        else{
            if(chk)v.push_back({start_pos, end_pos});
        
            tmp = arr[i];
            start_pos = i;
            cnt = 1;
            chk = false;
            end_pos++;
        }
    }
    //<--!!!-->
    if(chk)v.push_back({start_pos, end_pos});

    //터뜨리기
    for(int i=0;i<v.size();i++){
        for(int j=v[i].first;j<=v[i].second;j++){
            arr[j] = 0;
        }
    }
    int bomb_end = 0;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            copy_arr[bomb_end] = arr[i];
            bomb_end++;
        }
    }
    
    for(int i=0;i<bomb_end;i++){
        arr[i] = copy_arr[i];
    }
    n = bomb_end;
    //cout << "벡터 크기: " << v.size() << '\n';
    return v.size();
}

void pro(){
    if(m == 1){
        cout << 0;
        return;
    }

    while(explotion());

    print();
}

void print(){
    cout << n << '\n';
    for(int i=0;i<n;i++){
        cout << arr[i] << '\n';
    }
}



int main() {
    // 여기에 코드를 작성해주세요.
    input();
    pro();

    return 0;
}