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

char s[1024];

int main(){
	int tq; scanf("%d", &tq);
	REP(iq, tq){
		int n; scanf("%d%s", &n, s);
		int mi = INT_MAX, mx = INT_MIN;
		REP(i, n){
			if(s[i] == '1'){
				SML(mi, i);
				LAR(mx, i);
			}
		}
		int ans;
		if(mi == INT_MAX){
			ans = n;
		} else {
			ans = max( (mx + 1)*2, (n - mi)*2 );
		}
		printf("%d\n", ans);
	}
}
