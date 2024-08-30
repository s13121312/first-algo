#include<bits/stdc++.h>
using namespace std;

int n;
int lc[28];
int rc[28];


void input(){
    cin >> n;

    char a,l,r;

    for(int i = 0;i < n;i++){
        cin >> a >> l >> r;
        if(l != '.'){
            lc[a-'A'] = l-'A';
        }else lc[a-'A'] = 0;

        if(r != '.'){
            rc[a-'A'] = r - 'A';
        }else rc[a-'A'] = 0;

    }
}

void preorder(int cur){
    cout << char(cur + 'A');
    if(lc[cur] != 0)preorder(lc[cur]);
    if(rc[cur] != 0)preorder(rc[cur]);
}

void inorder(int cur){
    
    if(lc[cur] != 0)inorder(lc[cur]);
    cout << char(cur + 'A');
    if(rc[cur] != 0)inorder(rc[cur]);
}
void postorder(int cur){

    if(lc[cur] != 0)postorder(lc[cur]);
    if(rc[cur] != 0)postorder(rc[cur]);
    cout << char(cur + 'A');
}


void pro(){

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);

}

int main(){

    input();
    pro();

    return 0;
}