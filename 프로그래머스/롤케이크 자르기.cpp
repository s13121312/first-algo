#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> topping)
{
    int answer = 0;

    map<int, int> l;
    map<int, int> r;

    for (int i = 0; i < topping.size(); i++)
    {
        if(l.find(topping[i])!=l.end()){
            l[topping[i]]++;
        }
        else{
            l[topping[i]]=1;
        }
    }

    for(int i = 0; i < topping.size(); i++){
        //l에있는걸 r이 들고감
        if(l.find(topping[i])!=l.end()){
            l[topping[i]]--;
            if(l[topping[i]]==0){
                l.erase(topping[i]);
            }
            if(r.find(topping[i])==r.end()){
                r[topping[i]]=1;
            }
            else{
                r[topping[i]]++;
            }
        }

        if(l.size() == r.size())
        {
            answer++;
        }
        
    }
    

    return answer;
}