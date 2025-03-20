#include <iostream>
using namespace std;

int n,t;
int arr[2][205];
int upper[205];
int down[205];

void input(){
    cin >> n;
    cin >> t;

    for(int i=0;i<n;i++){
        cin >> upper[i];
    }
    for(int i=0;i<n;i++){
        cin >> down[i];
    }

}

void turn(){
    
    int tmp_u = upper[n-1];
    for(int i=n-1;i>=1;i--){
        upper[i] = upper[i-1];
    }

    int tmp_d = down[n-1];
    for(int i=n-1;i>=1;i--){
        down[i] = down[i-1];
    }
    upper[0] = tmp_d;
    down[0] = tmp_u;
}

void pro(){

    for(int i=0;i<t;i++){
        turn();
    }

    for(int i=0;i<n;i++){
        cout << upper[i] << ' ';
    }
    cout << '\n';

    for(int i=0;i<n;i++){
        cout << down[i] << ' ';
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    input();
    pro();

    return 0;
}