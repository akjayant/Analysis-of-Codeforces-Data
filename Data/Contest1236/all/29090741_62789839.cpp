#include<bits/stdc++.h>
#define ri register int
#define forn(i, n) for(int i = 1; i <= (n); i++)
typedef long long ll;
using namespace std;
/* Template_In_Programming_Contest */

void rd(int& u) {scanf("%d", &u);}
void rd2(int& u, int& v) {scanf("%d%d", &u, &v);}
void rd3(int& u, int& v, int& w) {scanf("%d%d%d", &u, &v, &w);}
void ptn(int u) {printf("%d\n", u);}
void pte(int u) {printf("%d ", u);}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
typedef vector <int> vi;

const int MOD = 1000000007;
int n, m;

int qpow(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = 1LL * res * a % MOD;
		a = 1LL * a * a % MOD;
		b >>= 1;
	}
	return res; 
}
int main(){
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> m;
	swap(m, n);
	// rep(i, 1, m) (1 << m) - 1
	
	
	ll pw = (qpow(2, n) - 1 + MOD) % MOD;
	cout << qpow(pw, m) << endl;
	return 0;
}