#include <bits/stdc++.h>

using namespace std;

int p, s, r;
int bob[110], alice[110];

int main() {
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		cin >> r >> p >> s;
		for(int i = 1; i <= n; i++) {
			char c; cin >> c;
			if(c == 'P') bob[i] = 1;
			if(c == 'S') bob[i] = 2;
			if(c == 'R') bob[i] = 3; 
			alice[i] = 0;
		} 
		int qwq = 0;
		for(int i = 1; i <= n; i++) {
			if(bob[i] == 1 && s) s--, alice[i] = 2, qwq++;
			if(bob[i] == 2 && r) r--, alice[i] = 3, qwq++;
			if(bob[i] == 3 && p) p--, alice[i] = 1, qwq++;
		}
		if(qwq * 2 < n) {
			puts("NO");
		} else {
			puts("YES");
			for(int i = 1; i <= n; i++) {
				if(alice[i]) {
					if(alice[i] == 1) cout << 'P' ;
					if(alice[i] == 2) cout << 'S' ;
					if(alice[i] == 3) cout << 'R' ;
				} else {
					if(p) cout << 'P', p--;
					else if(s) cout << 'S', s--;
					else cout << 'R' ;
				}
			}
			puts("");
		}
	}
	return 0;
}