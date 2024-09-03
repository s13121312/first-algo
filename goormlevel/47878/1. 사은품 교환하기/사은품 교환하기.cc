#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t;
vector<ll> ans;

//쿠폰을 구성하는 n은 최소 5개이상이어야한다는점


//쿠폰으로 얻을 수 있는 상품의 수를 계산하는 함수
void chk(ll n, ll m){
	ll tmp = 0;
	

	//n, m 
	tmp += min(n/5, m/7);
	n -= 5*tmp;
	m -= 7*tmp;
	
	//n이 5이상 && m+n이 12이상인경우인데 남은 m들을 처리하는과정.
 	//8 4 요런것들을 처리해줌. m남은 것들을 처리해줌.
	if(n>=5 && m+n>=12){
		n -= (12-m);
		m=0;
		tmp++;
	}
	
	//남은 n이 12 이상인경우를 처리해줌.
	tmp += n/12; //n을 12로 다 쓰는경우를 더해줘야함 m=0이므로
	
	ans.push_back(tmp);
}

void pro(){
	for(auto a: ans){
		cout << a <<'\n';
	}
}

void input(){
	cin >> t;
	for(int i=0;i<t;i++){
		ll n, m; // 시즌, 일반
		cin >> n >> m;
		chk(n, m);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	pro();
	
	
	return 0;
}