#include<bits/stdc++.h>

using namespace std;

typedef long long INT;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int T;
	cin >> T;
	while(T--) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = (a + c - 1) / c;
		int y = ( b + d - 1) / d;
		if(x + y <= k) cout << x << ' ' << y << endl;
		else cout << -1 << endl;
	}



	return 0;
}

        