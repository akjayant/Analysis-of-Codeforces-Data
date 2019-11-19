#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define ALL(a) (a).begin(), (a).end()
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

ll z[30][2][2];

ll f(int a, int b) {
	DEBUG("\n\nf(%d, %d) ============\n", a, b);
	REP(i, 30){
		REP(j, 2) REP(k, 2){
			// j ... whether upper digit is strictly less than a
			// k ... whether upper digit is strictly less than b

			ll &cur = z[i][j][k];
			cur = 0;

			REP(l, 3){
				int p = l%2, q = l/2;
				// p ... candidate digit of a
				// q ... candidate digit of b
				int r = (a>>i)&1, s = (b>>i)&1;
				// r ... i-th digit of a
				// s ... i-th digit of b

				if(!j && r < p) continue;
				if(!k && s < q) continue;

				int jj = (j || r>p) ? 1 : 0;
				int kk = (k || s>q) ? 1 : 0;
				
				if(i == 0){
					if(jj && kk) cur ++;
				} else {
					cur += z[i-1][jj][kk];
				}
			}

			DEBUG("z[%d][%d][%d] = %lld\n", i, j, k, cur);
		}
	}

	return z[29][0][0];
}

int main(){
	int n; scanf("%d", &n);
	REP(i, n){
		int a, b; scanf("%d%d", &a, &b); b++;
		printf("%lld\n", f(b, b) - f(a, b) * 2 + f(a, a));
	}
}
