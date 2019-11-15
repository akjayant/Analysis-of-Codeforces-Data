#include <bits/stdc++.h>

using namespace std;

string s;
int f[100010];

signed main() {
	cin >> s;
	int n = s.length();
	f[1] = 1;
	f[0] = 1;
	// while(!isalpha(s[n - 1])) n--;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'w' || s[i] == 'm') {
			puts("0");
			return 0;
		}
	}
	for(int i = 2; i <= n; i++) {
		f[i] = f[i - 1];
		if(s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n')) f[i] += f[i - 2]; 
		f[i] %= 1000000007; 
	}
	// for(int i = 1; i <= n; i++) cout << f[i] << " ";
	// puts("");
	cout << f[n] << endl;
	return 0;
}