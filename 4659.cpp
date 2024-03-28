#include<bits/stdc++.h>
using namespace std;

char moeum[5] = {'a','e','i','o','u'};
vector<char> mm = {'a','e','i','o','u'};
bool one(string input){
    bool first =false;
    
    for(int i=0;i<input.size();i++){
        for(int j=0;j<5;j++){
            if(input[i]==moeum[j]){
                first = true;
                break;
            }
        }
        if(first)break;
    }
    if(!first) return false;
    else{
        return true;
    }
}

bool three(string input){

    for(int i=0;i<input.size()-1;i++){
        if(input[i] == input[i+1]){
            if(input[i]=='e' || input[i] == 'o') continue;
            return false;
        }
    }
    return true;
}

bool two2(string input){
    int j_c=0;
    int m_c=0;
    for(int i=0;i<input.size();i++){
        if(find(mm.begin(), mm.end(), input[i]) != mm.end()){
            //있으면
            m_c++;
            j_c=0;
            if(m_c==3){
                return false;
            }
        }
        else{
            j_c++;
            m_c=0;
            if(j_c==3){
                return false;
            }
        }
    }
    return true;
}


int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    while (1)
    {
        cin >> str;
        if(str == "end") break;
        bool check = true;
        if(!one(str)){
            cout << "<" << str <<"> is not acceptable." << '\n';
            continue;
            check=false;
        }
        if(!two2(str)){
            cout << "<" << str <<"> is not acceptable." << '\n';
            continue;
            check=false;
        }
        if(!three(str)){
            cout << "<" << str <<"> is not acceptable." << '\n';
            continue;
            check=false;
        }
        if(check){
            cout << "<" << str << "> is acceptable."<< '\n';
        }            
    }
    

    return 0;
}