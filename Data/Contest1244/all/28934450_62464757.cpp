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

bool check(){
	int a, b, c, d, x; scanf("%d%d%d%d%d", &a, &b, &c, &d, &x);
	REP(j, 101){
		REP(k, 101){
			if(j + k > x) continue;
			if(c*j >= a && d*k >= b){
				printf("%d %d\n", j, k);
				return true;
			}
		}
	}
	return false;
}
int main(){
	int n; scanf("%d", &n);
	REP(i, n){
		if(!check()){
			printf("-1\n");
		}
	}
}
