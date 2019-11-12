//                             In The Name Of Allah
#include <iostream>
#define ss second
#define ff first
#define use_fast ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define ret(n) r1eturn cout << n, 0
#define se(n) cout << setprecision(n) << fixed
#define pb push_back
#include <vector>
#define int long long
using namespace std; 
 
const int N = 2e5 + 1000, OO = 1e18, M = 1e9 + 7, P = 6151, sq = 1e3, lg = 60;
typedef pair <int, int> pii;

int pw(int x, int y) {
	if(x == 0)
		return 1;
	int cnt = pw(x / 2, y);
	cnt = (cnt * cnt) % M;
	if(x % 2 == 1)
		cnt = (cnt * y) % M;
	return (cnt % M);
}

int32_t main() {
	use_fast;
	int n, m;
	cin >> n >> m;
	int t = (pw(m, 2) - 1 + M) % M;
	t = pw(n, t);
	t %= M;
	cout << t << endl;
 	return 0;
} 
/*
be carefull :
1- if not solve after 20 min, read again twice
2- after submit read the code again
3- fun with contest
4- ... 
*/
