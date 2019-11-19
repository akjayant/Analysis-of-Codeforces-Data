#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define ph push
#define f first
#define s second
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define btinpct(x) __builtin_popcountll((x))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string inline to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?b:gcd(b%a,a); }

#define ll long long int 
#define ld long double
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
typedef pair <ll, ll> pi; typedef pair <ll, pi> spi; typedef pair <pi, pi> dpi;

#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (2006)
ll n;
pi A[MAXN];
ll C[MAXN], K[MAXN];
bitset<MAXN> paid;
struct ufds_ {
	int p[MAXN];
	ufds_ () {
		FOR(i,0,MAXN-1) p[i]=i;
	}
	void merge(ll x,ll y){
		x=find(x), y=find(y);
		if(x==y) return;
		p[x]=y;
		paid[y] = paid[y] | paid[x];
	}
	ll find(ll x) { return (p[x]==x)?x:p[x]=find(p[x]); }
} ufds;
ll mdist(pi a, pi b) { return llabs(a.f-b.f) + llabs(a.s-b.s); }
vector<spi> e;

int main()
{
	FAST
	cin>>n;
	FOR(i,0,n-1) cin>>A[i].f>>A[i].s;
	FOR(i,0,n-1) cin>>C[i];
	FOR(i,0,n-1) cin>>K[i];
	FOR(i,0,n-1) FOR(j,i+1,n-1) {
		e.eb(mdist(A[i], A[j])*(K[i]+K[j]), pi(i, j));
	}
	FOR(i,0,n-1) e.eb(C[i], pi(i, i));
	sort(all(e));
	ll ans = 0;
	vector<int> build;
	vector<pi> edge;
	for(auto i:e) {
		ll a = i.s.f, b=i.s.s, c=i.f;
		if(i.s.f ^ i.s.s) {
			if(ufds.find(a) == ufds.find(b)) continue;
			if(paid[ufds.find(a)] && paid[ufds.find(b)]) continue;
			ans += c;
			edge.eb(a, b);
			ufds.merge(a, b);
		} else {
			if(paid[ufds.find(a)]) continue;
			paid[ufds.find(a)]=1;
			ans += c;
			build.pb(a);
		}
	}
	cout<<ans<<'\n';
	cout<<build.size()<<'\n';
	for(auto i:build) {
		cout<<i+1<<' ';
	}
	cout<<'\n';
	cout<<edge.size()<<'\n';
	for(auto i:edge) {
		cout<<i.f+1<<' '<<i.s+1<<'\n';
	}
}
