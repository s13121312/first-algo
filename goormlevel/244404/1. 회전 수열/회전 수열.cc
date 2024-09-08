#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[10005];

void input(){

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
}

void chk(){
    for(int i=0;i<n;i++){
        cout << arr[i] << ' ';
    }
    cout<< '\n';
}

void rotate(int ct){ // ct번 회전할때 arr가 변하는
    for(int d=0;d<ct;d++){            
        int last = arr[0];
        for(int j=1;j<n;j++){
            arr[j-1]= arr[j];    
        }
        arr[n-1] = last;
    }
}

//m번회전하는데 맨 왼쪽의 수는 맨오른쪽으로 이동
//맨 왼쪽의 수만큼 왼쪽으로 회전.
//최종 수열의첫 번째 값만 알면됨.
void pro(){
    int head = 0;
    //이러면 시간초과날듯.
    for(int i=0;i<m;i++){
        int ct = arr[0];
        head = (head+arr[head])%n;
    }

    
    cout << arr[head];
}

int main(){

    input();
    pro();

    return 0;
}