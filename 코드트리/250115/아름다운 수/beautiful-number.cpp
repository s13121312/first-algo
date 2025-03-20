#include <iostream>
using namespace std;

int n;
int arr[15];
int cnt =0;

bool chk(){
    for(int i=0;i<n;i++){
        for(int j=1;j<arr[i];j++){
            if(arr[i] != arr[i+j])return false;
        }
        i = i+arr[i]-1;
    }
    return true;
}
void print(){
    for(int i=0;i<n;i++){
        cout << arr[i];
    }
    cout << '\n';
}
void pro(int idx){
    if(idx == n){
        //print();

        if(chk()){
            cnt++;
            //print();
        }

        return;
    }


    for(int i=1;i<=4;i++){
        arr[idx] = i;
        pro(idx+1);
        arr[idx] = 0;
    }

}


int main() {
    // Please write your code here.
    cin >> n;
    pro(0);
    cout << cnt;


    return 0;
}