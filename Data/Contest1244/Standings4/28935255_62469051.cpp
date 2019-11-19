#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef pair<int, ii> tri;
typedef vector<tri> viii;

#define fi(i,a,b) for(auto i=a;i<b;i++)
#define trav(i,v) for(auto &i: v)
#define fd(i,a,b) for(auto i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mt make_tuple
#define ss second
#define ff first
#define sz(a) a.size()
#define sc(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d %d", &x, &y)
#define sc3(x) scanf("%s", x)
#define sc4(x) scanf("%lld", &x)
#define sc5(x, y) scanf("%lld %lld", &x, &y)
#define sc6(x) scanf("%lf", &x)
#define sc7(x, y) scanf("%lf %lf", &x, &y)
#define mse(a, x) memset(a, x, sizeof(a))
#define mod 1000000007

#define TRACE
#ifdef TRACE
	#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
		
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << ": " << arg1 << std::endl;
	}

	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ',');
		cerr.write(names, comma - names) << ": " << arg1<<" |";
		__f(comma+1, args...);
	}
#else
	#define trace(...) ;
#endif

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main() {
	int t;
	sc(t);
	while(t--) {
		int n;
		sc(n);
		char s[n+1];
		sc3(s);
		int res = n;
		int maxm = -1, minm = n;
		fi(i, 0, n) {
			if(s[i] == '1') {
				maxm = max(maxm, i);
				minm = min(minm, i);
			}
		}
		if(maxm != -1) {
			res = max(res, n+1);
			res = max(res, 2*maxm + 2);
			res = max(res, 2*(n-minm));
		}

		printf("%d\n", res);
	}
	return 0;
}
