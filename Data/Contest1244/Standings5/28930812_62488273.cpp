/*input
3
7 5 4 5 8
7 5 4 5 2
20 53 45 26 4
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define pb push_back
#define f first
#define s second
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
	IOS;
	int t;
	cin >> t;
	while(t--){
		int a,b,c,d,k;
		cin >> a >> b >> c >> d >> k;
		int t = ceil((double)(a)/c) + ceil((double)(b)/d);
		if(t > k){
			cout << -1 << "\n";
			continue;
		}
		cout << ceil((double)(a)/c) << " " << ceil((double)(b)/d) << endl;

	}

return 0;
}
