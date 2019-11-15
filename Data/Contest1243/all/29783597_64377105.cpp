#include <bits/stdc++.h>
#define ii pair <int, int>
#define x first
#define y second
#define db(x) cerr << #x << " = " << x << endl;
#define _ << " _ " <<

using namespace std;

int test, n, d;
int diff[100000];
string s, t;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	if(fopen("test.inp", "r")) freopen("test.inp", "r", stdin), freopen("test.out", "w", stdout);
	cin >> test;
	while (test--){
		cin >> n;
		cin >> s >> t;
		s = ' ' + s;
		t = ' ' + t;
		d = 0;
		for (int i = 1; i <= n; i++)
			if (s[i] != t[i])
				diff[++d] = i;
		if (d == 0){
			puts("Yes");
			continue;
		}
		if (d != 2){
			puts("No");
			continue;
		}
		swap(s[diff[1]], t[diff[2]]);
		if (s == t)
			puts("Yes");
		else 
			puts("No");
		// if (check(s, t, diff[1], diff[2])) {
		// 	puts("Yes");
		// 	continue;
		// }
	}
}