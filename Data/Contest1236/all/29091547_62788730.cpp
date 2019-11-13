#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int qtt;
	cin >> qtt;

	while(qtt--){

		int a, b, c, ans = 0;
		cin >> a >> b >> c;

		ans = min(b, c/2);
		b -= ans;
		ans += min(a, b/2);

		cout << 3*ans << '\n';
	}

	return 0;
}