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
		string s, t;
		cin >> s >> t;
		
		int cnt = 0;

		vector<pair<int, int > > out;
		for(int i = 0; i<n; i++) {
			if(s[i] == t[i]) {
				swap(s[i], t[i]);
				out.pb({i+1, i+1});
				cnt += 1;	
			}
			else {
				for(int j = i+1; j<n; j++) {
					if(s[j] == s[i]) {
						swap(s[j], t[i]);
						out.pb({j+1, i+1});
						cnt++;
						break;
					}
					else if(t[j] == s[i]) {
						swap(t[j], s[i+1]);
						//cout << s << '\n' << t << "\n\n";
						out.pb({i+2, j+1});
						swap(s[i+1], t[i]);
						//cout << s << '\n' << t << "\n\n";
						out.pb({i+2, i+1});
						cnt+=2;
						break;
					}
				}
			}
		} 
	
		int ok = 1;
		
		if(cnt > 2*n) {
			ok = 0;
		}
		for(int i = 0; i<n; i++) {
			if(s[i] != t[i]) ok = 0;
		}
		
		if(!ok) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			cout << cnt << '\n';
			for(int i = 0; i<int(out.size()); i++) cout << out[i].fi << ' ' << out[i].se << '\n';
		}
	}
	return 0;
}

