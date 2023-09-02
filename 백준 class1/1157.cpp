#include <bits/stdc++.h>
using namespace std;
int freq[26];
string c;

int main(void)
{
    
    cin >> c;
    
    for(int i=0;i<c.length();i++)
    {
        freq[c[i]-'a']++;
    }
    
    int max = 0;
    int cnt=0;
    int max_indx=0;
    for(int i=0;i<26;i++)
    {
        if(max<freq[i])
        {
            max=freq[i];
            max_indx=i;
            cnt=0;
        }    
    }
    for(int i=0;i<26;i++)
    {
        if(max==freq[i])
        {
            cnt++;
        }   
    }
    if(cnt>1)
    {
        cout << "?";
    }
    
    else 
    {
        cout << (char)(max_indx+'A');
    }
            
    return 0;
}