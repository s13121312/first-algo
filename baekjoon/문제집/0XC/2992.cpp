#include<bits/stdc++.h>
using namespace std;

int x;
//X와 구성이 같으면서 X보다 큰 수 중 가장 작은 수를 출력
vector<int> arr;
int s = 0;

vector<int> result;
bool isused[10];
bool is_check = false;
void func(string a){
    
    if(a.size() == arr.size()){
        int t = stoi(a);
        if(x < t){
            result.push_back(t);
            is_check = true;
        }
        return;
    }

    for(int i=0;i<arr.size();i++){
        if(!isused[i]){
            isused[i]=true;
            func(a + to_string(arr[i]));
            isused[i]=false;
        }
    }

}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> x;
    int tmp = x;
    while (tmp > 0)
    {  
        int a = tmp%10;
        arr.push_back(a);
        tmp/=10;
    }
    reverse(arr.begin(),arr.end());
    
    
    func("");

    sort(result.begin(),result.end());
    if(!is_check){
        cout << 0;
    }
    else{
        cout << result[0];
    }
    return 0;
}