#include<bits/stdc++.h>
using namespace std;

int l,n;
int isused[1002];
vector<pair<int,int>> v;
int ans_1=0;//가장많은 조각을 받을것으로 기대하고 있던 방청객의번호
int answer1=0;
int ans_2=0;
int ans2_cnt=0;
int answer2=0;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> l;
    cin >> n;
    fill(isused,isused+n,0);
    for(int i=0;i<n;i++)
    {
        ans_2=0;
        int a,b;
        cin >>a >> b;
        v.push_back({a,b});
        for(int j=a;j<=b;j++)
        {
            if(isused[j]==0)//방문하지않았을때
            {     
                isused[j]=i+1;
                ans_2++;
            }
            
        }
        if(ans2_cnt<ans_2){
            ans2_cnt=ans_2;
            answer2=i+1;
        }
        if(ans_1 < (b - a)){
            ans_1= b - a;
            answer1=i+1;
        }

    }

    cout << answer1 << '\n' << answer2; 
    return 0;
}