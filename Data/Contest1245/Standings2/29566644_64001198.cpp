#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e5 + 5;

void solve (void){
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	string s;
	int win = 0;
	vector <char> res(n, '?');
	cin >> s;
	for (int i=0; i<n; ++i){
		if (s[i] == 'R'){
			if (b) {win++;--b; res[i] = 'P';}
		}
		else if (s[i] == 'P'){
			if (c) {win++; --c; res[i] = 'S';}
		}
		else {
			if (a){win++; --a; res[i] = 'R';}
		}
	}
	int need = n/2 + n%2;
	if (win < need) cout << "NO" << '\n';
	else {
		cout << "YES\n";
		for (int i=0; i<n; ++i){
			if (res[i] != '?') cout << res[i];
			else {
				if (a) { --a; cout << 'R';}
				else if (b) {--b; cout << 'P';}
				else if (c) {--c; cout << 'S';}
			}
		}
		cout << '\n';
	}
}	

signed main (void){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while (T--) solve ();
}

