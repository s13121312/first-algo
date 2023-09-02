/*#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cntWord = 0;
  while (true) {
    string word; cin >> word;
    if (cin.eof()) break ;
    cntWord++;
  }

  cout << cntWord << "\n";

  return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main(){	
	int ans = 1, i=0;
	char str[1000001];

	gets(str);
	
	for (i=1; str[i]; i++)
		if (str[i] == ' ') ans++;

	if (str[i - 1] == ' ') ans--;
	cout<<ans;
	return 0;
}