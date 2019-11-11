#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	string s;
	cin >> s;
	int a2=0, b2=0, c2=0;
	for(int i=0; i<s.size(); ++i) {
		if(s[i]=='S') {
			++a2;
		} else if(s[i]=='R') {
			++b2;
		} else {
			++c2;
		}
	}
	int ans=min(a, a2)+min(b, b2)+min(c, c2);
	if(ans*2>=n) {
		cout << "yes\n";
		string t;
		for(int i=0; i<s.size(); ++i) {
			if(s[i]=='S'&&a) {
				--a;
				t+='R';
			} else if(s[i]=='R'&&b) {
				--b;
				t+='P';
			} else if(s[i]=='P'&&c) {
				--c;
				t+='S';
			} else {
				t+='*';
			}
		}
		for(int i=0; i<s.size(); ++i) {
			if(t[i]^'*') {
				continue;
			}
			if(a) {
				--a;
				t[i]='R';
			} else if(b) {
				--b;
				t[i]='P';
			} else if(c) {
				--c;
				t[i]='S';
			}
		}
		cout << t << "\n";
	} else {
		cout << "no\n";
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}