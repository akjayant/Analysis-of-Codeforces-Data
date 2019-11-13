#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int T;

int n, a, b, c, ans;

string s;

char chu[111];

void solve() {
	ans = 0;
	cin >> n >> a >> b >> c >> s;
	for(int i = 1; i <= n; i++) chu[i] = ' ';
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'S' && a) {
			chu[i+1] = 'R';
			a--;
		}
		if(s[i] == 'R' && b) {
			chu[i+1] = 'P';
			b--;
		}
		if(s[i] == 'P' && c) {
			chu[i+1] = 'S';
			c--;
		}
	}
	for(int i = 1; i <= n; i++)
		if(chu[i] != ' ') ans++;
	if(ans < (n+1)/2) cout << "NO" << endl;
	else {
		cout << "YES" <<endl;
		for(int i = 1; i <= n; i++) {
			if(chu[i] != ' ') cout <<chu[i];
			else {
				if(a) cout << 'R', a--;
				else if(b) cout << 'P', b--;
				else if(c) cout << 'S', c--; 
			}
		}
		cout << endl;
	}
}

int main() {
	cin >> T;
	while(T--) solve();
	return 0;
}