#include <bits/stdc++.h>
using namespace std;

signed main(){
	int T; cin >> T;
	while(T--){
		int a,b,c,d,k;
		cin >> a >> b >> c >> d >> k;
		int x = a/c+(a%c > 0);
		int y= k -x;
		if(y*d >= b) cout << x << " " << y << "\n";
		else cout << "-1\n";
	}
}
