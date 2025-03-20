#include <iostream>
using namespace std;

int n;
int arr[105];
int arr_size = 0;
//a부터 b까지 빼기
void pro(int a, int b){
    int tmp[105];

    for(int i=a;i<=b;i++){
        arr[i] = 0;
    }

    int idx=0;
    for(int i=0;i<n;i++){
        if(arr[i] != 0){
            tmp[idx] = arr[i];
            idx++;
        }
    }
    
    for(int i=0;i<idx;i++){
        arr[i] = tmp[i];
    }

    n = idx;
}

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<2;i++){
        int s, e;
        cin >> s >> e;
        s--;
        e--;
        pro(s,e);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    input();

    cout << n << '\n';
    for(int i=0;i<n;i++){
        cout << arr[i] <<'\n';
    }
    return 0;
}