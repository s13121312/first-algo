#include <bits/stdc++.h>
using namespace std;

int r, c, k;
int arr[105][105];
int tmp[55][55];
int row= 0;    //열
int column = 0;   //행
int cnt = 0; //시간

void input(){
    cin >> r >> c >> k;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin >> arr[i][j];
        }
    }
}

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.second == b.second)return a.first < b.first;
    return a.second < b.second;
}
bool chkEqual(){
    if(arr[r-1][c-1] == k){
        return true;
    }
    return false;
}

void print(){
    for(int i=0;i<column;i++){
        for(int j=0;j<row;j++){
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void verify(){
    if(row >=100 || column >=100){
        //TODO 처음 100개의 격자를 제외하고 모두 버리기
        for(int i=100;i<column;i++){
            for(int j=0;j<row;j++){
                arr[i][j] = 0;
            }
        }
        for(int i=100;i<row;i++){
            for(int j=0;j<column;j++){
                arr[i][j] = 0;
            }
        }
    }

     
    if(column >= row){
        for(int i=0;i<column;i++){
            int number[103] = {0, }; //배열안의 수 카운트  vector<int> v(100,0)
            vector<int> num;//나온 숫자들
            for(int j=0;j<row;j++){
                if(arr[i][j] != 0){
                    if(number[arr[i][j]] == 0) {
                        num.push_back(arr[i][j]);
                    }       
                    number[arr[i][j]]++;
                }     
            }
            vector<pair<int, int>> numbers;
            for(auto x: num){
                numbers.push_back({x, number[x]});   //숫자, 숫자의 개수
            }
            sort(numbers.begin(), numbers.end(), cmp);

            
            //정렬 후 행 덧대기
            int r;
            for(r=0;r<numbers.size();r++) {
                arr[i][2*r] = numbers[r].first;
                arr[i][2*r+1] = numbers[r].second;
            }
            
            
            row = max(row, (int)numbers.size()*2); //중간에 바뀌어도 상관이 없는가? yes 어차피 0은 제외해줫으니까
            //cout << "r: " << r;
            for(int j=2*r;j<row;j++) {
                arr[i][j] = 0;
            }
        }
    } else if(row > column){
        for(int i=0;i<row;i++){
            int number[103] = {0, }; 
            vector<int> num;
            for(int j=0;j<column;j++){
                if(arr[j][i] != 0){
                    if(number[arr[j][i]] == 0) {
                        num.push_back(arr[j][i]);
                    }       
                    number[arr[j][i]]++;
                }
            }

            vector<pair<int, int>> numbers;
            for(auto x: num){
                numbers.push_back({x, number[x]});   //숫자, 숫자의 개수
            }
            sort(numbers.begin(), numbers.end(), cmp);

            //정렬 후 열 덧대기
            int c;
            for(c=0;c<numbers.size();c++) {
                arr[2*c][i] = numbers[c].first;
                arr[2*c+1][i] = numbers[c].second;
            }
            
            column = max(column, (int)numbers.size()*2);
            for(int j=2*c;j<column;j++) {
                arr[j][i] = 0;
            }
        }
    }

    //print();
}

void pro(){

    column =3;
    row = 3;
    while(1){
        if(chkEqual()){
            break;
        }
        verify();
        cnt++;
        //cout << cnt << ' ';
        if(cnt > 100){
            cout << -1;
            return;
        }
    }

    cout << cnt;
}


int main() {
    // Please write your code here.
    input();
    pro();


    return 0;
}