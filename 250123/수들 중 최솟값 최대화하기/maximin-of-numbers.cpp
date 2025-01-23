#include <iostream>
#include <vector>
using namespace std;

int n;
int arr[15][15];
int visit[15];  //열 체크
int ans = 0;

void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
}
vector<int> selected;

int calcMin(){
    int minVal = 10005;
    for(int i=0;i<selected.size();i++){
        minVal = min(minVal, selected[i]);
    }
    return minVal;
}
void print(){
    for(auto x: selected){
        cout << x << ' ';
    }
    cout << '\n';
}
void pro(int depth){
    if(depth == n){
        ans = max(ans, calcMin());
        //print();
        //cout << ans << '\n';
        return;
    }

    for(int i=0;i<n;i++){
        if(visit[i])continue;
        visit[i] = true;
        selected.push_back(arr[depth][i]);
        pro(depth+1);
        visit[i] = false;
        selected.pop_back();
    }   
}

int main() {
    // Please write your code here.
    input();
    pro(0);
    cout << ans;

    return 0;
}