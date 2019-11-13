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

#define N 112345
char s[N];
#define MOD 1'000'000'007LL
ll a[N];

int main(){
	scanf("%s", s); int n = strlen(s);
	a[n] = 1;
	for(int i = n-1; i >= 0; i--){
		a[i] = a[i+1];
		if(s[i] == s[i+1]){
			if(s[i] == 'u' || s[i] == 'n'){
				a[i] += a[i+2];
			}
		}
		a[i] %= MOD;
	}
	REP(i, n) if(s[i] == 'm' || s[i] == 'w') a[0] = 0;
	printf("%lld\n", a[0]);
}
