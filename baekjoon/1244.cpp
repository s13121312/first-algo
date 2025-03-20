#include<bits/stdc++.h>
using namespace std;

int s[105];

typedef struct str
{
    int gender;
    int num;
}st;


void func(){

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }

    int stud;
    cin >> stud;
    vector<st> v(stud+1);
    for(int i=0;i<stud;i++){
        cin >> v[i].gender >> v[i].num;
    }
    
    for(int i=0;i<stud;i++){
         
        if(v[i].gender == 1){ //남
            for(int j=1;j<=n;j++){
                if(j % v[i].num == 0){
                    if(s[j]==1) s[j]=0;
                    else{
                        s[j]=1;
                    }
                }
            }
        }
        if(v[i].gender == 2){ //여
            int q = v[i].num;
            
            if(s[q] == 1){
                s[q]=0;
            }
            else{
                s[q]=1;
            }
            //q를 중심으로 1칸씩 퍼져가기
            for(int j=1;j<n;j++){
                if((q-j) < 1 || (q+j) > n)break;

                if(s[q-j] == s[q+j]){
                    if(s[q-j]==1){
                        s[q-j]=0;
                        s[q+j]=0;
                    }
                    else{
                        s[q-j]=1;
                        s[q+j]=1;
                    }
                }
                else{break;}
            }
           
        }
    }

    for(int i=1;i<=n;i++){
        cout << s[i] << ' ';
        if(i%20 ==0)cout << '\n';
    }


    return 0;
}