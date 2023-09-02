#include <bits/stdc++.h>
using namespace std;
//int freq1[26],freq2[26];
string s1,s2;
/*int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a,b;
    //전역변수로 설정해줘야됨 알파벳들
    cin >>a;
    cin >>b;
    for(int i=0;i<a.size();i++)
    {
        freq1[a[i]-'a']++;
    }
    for(int i=0;i<b.size();i++)
    {
        freq2[b[i]-'a']++;
    }
    
    int cnt=0;
    for(int i=0;i<26;i++)
    {
        if(freq1[i]<freq2[i])
        {
            cnt+=(freq2[i]-freq1[i]);
        }
        else if(freq1[i]>freq2[i])
        {
            cnt+=(freq1[i]-freq2[i]);
        }
    }
    cout <<cnt;
}*/
int arr[2][26],res;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >>s1>>s2;
    for(char c : s1)
    {
        arr[0][c-'a']++;
    }
    for(char c : s2)
    {
        arr[1][c-'a']++;
    }
    for(int i=0;i<26;i++)
    {
        res += abs(arr[0][i]-arr[1][i]);
    }
}