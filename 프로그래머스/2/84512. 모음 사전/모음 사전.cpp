#include <string>
#include <vector>

using namespace std;
int cnt = 0;
string aeiou = "AEIOU";
string target;
int ans = 0;

void dfs(string cur) {
    if(cur.size()>=6)return;
    if(cur == target) {
        ans = cnt;
        return;
    }    
    
    
    cnt++;
    for(int i=0;i<5;i++) {
        dfs(cur + aeiou[i]);        
    }
}
int solution(string word) {
    target = word;

    dfs("");
    
    return ans;
}