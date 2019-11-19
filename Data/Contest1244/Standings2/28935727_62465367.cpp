#include<bits/stdc++.h>
using namespace std;

int main(){
	int tests; cin >> tests;
	for(int t=0; t<tests; ++t){
		int a, b, c, d, k; cin >> a >> b >> c >> d >> k;
		int ans1, ans2;
		ans1=(a+c-1)/c;
		ans2=(b+d-1)/d;
		if(ans1+ans2>k) cout << -1 << endl;
		else cout << ans1 << " " << ans2 << endl;
	}
}
