#include<bits/stdc++.h>
using namespace std;

int n, t, m;

void plusho(int time){
    int hour = time/60;

    time -= hour*60;
    int bun = time;
    
    t += hour;
    m += bun; 
    if(m >=60){
        m %=60;
        t++;
    }
    if(t>=24){
        t = t % 24;
    }
}

void input(){
    cin >> n;
    cin >> t >> m;
    while (n--)
    {
        int a;
        cin >> a;
        plusho(a);
    }
    

}



int main(){

    input();
    cout << t << ' ' << m;
    return 0;
}