#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define tc(t) int t;cin >> t; while(t--)
#define pb push_back
#define fi first
#define se second
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cerr << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);

int main() {_
	tc(t) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string t;
		cin >> t;
		
		vector<int> pos;
		for(int i = 0; i<n; i++) {
			if(s[i] != t[i]) {
				pos.pb(i);
			}
		}
		
		int si = int(pos.size());
		
		if(si == 0) {
			cout<<"YES\n";
		}
		else if(si == 1) {
			cout<<"NO\n";
		}
		else if(si == 2) {
			int x = pos[0];
			int y = pos[1];
			
			if(s[x] == s[y] && t[x] == t[y]) {
				cout<<"YES\n";
			}
			else cout<<"NO\n";
		}
		else {
			cout<<"NO\n";
		}
	}
	return 0;
}

