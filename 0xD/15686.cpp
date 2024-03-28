#include<bits/stdc++.h>
using namespace std;

int n,m;
int answer=99999999;
int city[52][52];
bool isused[13];
vector<pair<int,int>> house,chicken, v; //집,치킨집,v는 조합


int distance(){
    int sum=0;//도시 치킨거리
    for(int i=0;i<house.size();i++) //집과 선택된 치킨집과의 거리를 구함
    {
        int x1= house[i].first;
        int y1 = house[i].second;
        int d=99999999;
        for(int j=0;j<v.size();j++)
        {
            int x2=v[j].first;
            int y2 = v[j].second;
            int dist = abs(x1-x2)+abs(y1-y2);
            d=min(dist,d);  
        }
        sum+=d;
    }
    return sum;
}

void select_chicken(int idx,int cnt){//치킨집 고르기 조합!
    if(cnt==m)
    {
        answer=min(answer, distance());
        return;
    }

    for(int i=idx;i<chicken.size();i++)
    {
        if(!isused[i])
        {
            isused[i]=true;
            v.push_back(chicken[i]);
            select_chicken(idx,cnt+1);
            isused[i]=false;
            v.pop_back();
        }
    }
}

int main(void)
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            cin >> city[i][j];
            if(city[i][j]==2)
            {
                chicken.push_back(make_pair(i,j));
            }
            if(city[i][j]==1)
            {
                house.push_back({i,j});
            }
        }
    }

    select_chicken(0,0);
    cout<<answer;
    return 0;
}