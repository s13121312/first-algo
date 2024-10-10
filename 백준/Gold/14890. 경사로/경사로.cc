#include<bits/stdc++.h>
using namespace std;

int n, l;
int board[105][105];

void input(){
    cin >> n >> l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }
}

bool outofRange(){

}

//2N번 봐야하는데 
//만약 한줄라인이 다 같은 숫자(높이)이면 ans증가
//아니라면 한줄이 될수있는지 돌려봐야함
//경사로는 높이가 항상 1이며, 길이는 L

/*6 1
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3      -> 11
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2*/

//line번째 라인
bool roadfinder(int line, string way){
    bool vis[105] = {false};    //놓은 경사로를 표시하기 위한 배열

    if(way == "width"){
        //가로 

        //TODO 경사로를 어떻게 처리할지를 "생각"해야함
        for(int i=0;i<n-1;i++){

            
            if(board[line][i] + 1 < board[line][i+1] || board[line][i] > board[line][i+1] + 1){
                return false;
            }else if(board[line][i] + 1 == board[line][i+1]){
                for(int k=0;k<l;k++){
                    if(board[line][i] == board[line][i-k]){
                        if(vis[i-k] || i-k < 0)return false;
                        vis[i-k] = true;
                        continue;
                    }else return false;
                }

            }else if(board[line][i] == board[line][i+1] + 1){
                for(int k=0;k<l;k++){
                    if(board[line][i+1] == board[line][i+1+k]){
                        if(vis[i+1+k] || i+1+k >= n)return false;
                        vis[i+1+k]=true;
                        continue;
                    }
                    else return false;
                }
            }
        }
        //cout << "w: " << line << '\n';
        return true;
        
    }else if(way == "height"){
        //세로
        for(int i=0;i<n-1;i++){
            if(board[i][line] + 1 <board[i+1][line] || board[i][line] > board[i+1][line] + 1){
                //이러면 경사로를 놓아도 의미가 없으니까 이 line은 넘어가면될듯
                return false;
            }else if(board[i][line] + 1 == board[i+1][line]){
                //경사로를 놓아보고
                for(int k=0;k<l;k++){
                    if(board[i][line] == board[i-k][line]){
                        if(vis[i - k] || i-k < 0)return false;
                        vis[i - k]=true;
                        continue;
                    }else return false;
                }
            }else if(board[i][line] == board[i+1][line] + 1){
                for(int k=0;k<l;k++){
                    if(board[i+1][line] == board[i+1+k][line]){
                        if(vis[i+1+k] || i+1+k >= n)return false;
                        vis[i+1+k]=true;
                        continue;
                    }
                    else return false;
                }
            }
        } 
        //cout << "h: "<<line << '\n';
        return true;
    }
}

int ans = 0;

void pro(){

    //한줄 씩 봐야겠지 일단? 먼저 가로축
    for(int i=0;i<n;i++){
        bool chk = true;
        for(int j=1;j<n;j++){

            if(board[i][j-1] != board[i][j])chk=false;
            if(!chk)break;
        }   
        if(!chk){
            //경사로를 넣어서 되는지 확인해봐야함
            if(roadfinder(i, "width"))ans++;
        }else{
            //cout << "same(w): " << i << '\n';
            ans++;
        } 
    }

    for(int i=0;i<n;i++){
        bool chk = true;
        for(int j=1;j<n;j++){
            if(board[j-1][i] != board[j][i])chk=false;
            if(!chk)break;    
        }   
        if(!chk){
            //경사로를 넣어서 되는지 확인해봐야함
            if(roadfinder(i, "height"))ans++;
        }else{
            //cout << "same(h): " << i << '\n';
            ans++;
        } 
    }

    cout << ans;
}


int main(){

    input();
    pro();

    return 0;
}