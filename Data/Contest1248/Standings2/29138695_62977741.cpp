#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int ans;

signed main(){
	int t; cin >> t;
	while(t--){
		cin >> n;
		int o1 = 0, e1 = 0;
		ans = 0;
		while(n--){
			int x; cin >> x;
			if(x%2==1) ++o1; else ++e1;
		}
		cin >>m;
		while(m--){
			int x; cin >> x;
			if(x%2==1) ans += o1; else ans+= e1;
		}
		cout << ans << "\n";
	}
}
