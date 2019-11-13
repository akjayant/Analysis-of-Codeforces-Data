/*input
2
3
1 1 1
RPS
3
3 0 0
RPS
10 10
1 10
6 9
7 3

*/
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define x firstw
#define y second
#define inf INT_MAX / 2ll
#define all(a) a.begin(), a.end()
#define db(a) cout << fixed << #a << " = " << a << endl;
#define ld long double
#define endl '\n'
using namespace std;
// #define int ll
// #pragma GCC optimize("Ofast")

//coding in car is hard
int32_t main(){
	int t;
	cin >> t;

	while(t--){
		int n;
		cin >> n;

		int r, p, s;
		cin >> r >> p >> s;

		string S;
		cin >> S;


		int beat = 0;
		string ans = string(n, '?');

		for(int i = 0; i < n; i++){
			if(S[i] == 'R' && p > 0) {ans[i] = 'P'; p--; beat++;};
			if(S[i] == 'P' && s > 0) {ans[i] = 'S'; s--; beat++;};
			if(S[i] == 'S' && r > 0) {ans[i] = 'R'; r--; beat++;};
		}

		for(int i = 0; i < n; i++){
			if(S[i] == 'R' && r > 0 && ans[i] == '?') {ans[i] = 'R'; r--;};
			if(S[i] == 'P' && p > 0 && ans[i] == '?') {ans[i] = 'P'; p--;};
			if(S[i] == 'S' && s > 0 && ans[i] == '?') {ans[i] = 'S'; s--;};
		}

		for(int i = 0; i < n; i++){
			if(S[i] == 'R' && s > 0 && ans[i] == '?') {ans[i] = 'S'; s--;};
			if(S[i] == 'P' && r > 0 && ans[i] == '?') {ans[i] = 'R'; r--;};
			if(S[i] == 'S' && p > 0 && ans[i] == '?') {ans[i] = 'P'; p--;};
		}

		if(beat >= round(n / 2.0)){
			cout << "YES" << endl << ans << endl;
		} else {
			cout << "NO" << endl;
		}


	}

}
