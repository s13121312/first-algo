#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    
    
    if (cacheSize == 0)
    {
        answer = 5*cities.size();
        return answer;
    }

    vector<string> q;
    for (int i = 0; i < cities.size(); i++)
    {
        string check = cities[i];
        
        //transform으로도 바꿀수있다
        for(int j=0;j<check.size();j++){
            check[j] = tolower(check[j]);
        }
        //auto로 형변환해줌
        auto id = find(q.begin(),q.end(),check);

        //q에 있을때
        if(id != q.end())
        {
            q.erase(id); // 주소를 반환해주는거니까 되는듯
            q.push_back(check);
            answer++;
        }
        else{ //q에없을때

            if(q.size()<cacheSize){
                q.push_back(check); 
            }
            else{
                q.erase(q.begin() + 0);
                q.push_back(check);
            }
            answer+=5;
        }
    }

    return answer;
}