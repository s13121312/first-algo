#include <bits/stdc++.h>
using namespace std;

pair<int, int > p[20];
vector<pair<int, int>> choose;
int n;
int ans = 0;
bool vis[20];
void input(){
    cin >> n;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        p[i] = {a, b};
    }

}

bool compare(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first)return a.second < b.second;
    return a.first < b.first;
    
}

//겹치면 true 반환
bool isMix(pair<int, int> a, pair<int, int> b){
    int x1 = a.first ,x2 = a.second; 
    int x3= b.first, x4 = b.second;
    if(((x3 >= x1) && (x3<=x2)) || ((x4 >= x1) && (x4 <= x2)) ||
        ((x1 >= x3) && (x1<=x4)) || ((x2 >= x3) && (x2<=x4))){
            return true;
    }   
    return false;
}

//안겹치면 true반환
bool notPaste(){

    //sort(choose.begin(), choose.end(), compare);

    for(int i=0;i<choose.size();i++){
        for(int j=i+1;j<choose.size();j++){
            if(i == j)continue;
            if(isMix(choose[i], choose[j]))return false;
        }
    }
    return true;
}

/*void pro(int idx){
    

    if(notPaste()){
        ans = max(ans, (int)choose.size());
        cout << choose.size() << ' ';
        return;
    }

    for(int i=idx;i<n;i++){
        if(vis[i])continue;
        choose.push_back(p[i]);
        vis[i] = true;
        pro(idx+1);
        choose.pop_back();
        vis[i] = false;
    }
}*/

void pro(int idx){
    
    if(idx == n){
        if(notPaste()){
            ans = max(ans, (int)choose.size());
            //cout << choose.size() << ' ';
        }
        return;
    }
    
    choose.push_back(p[idx]);
    pro(idx+1);
    choose.pop_back();

    pro(idx+1);

}



int main() {
    // Please write your code here.
    input();
    pro(0);
    cout << ans;

    return 0;
}