#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define pf(x) printf("%d\n",x)
#define pfl(x) printf("%lld\n",x)
#define flash ios_base::sync_with_stdio(false);cin.tie(0)
#define goog(x) cout << "Case #" << x << ": "
#define MAX5 200005
#define MAX6 2000005
#define MLOG 18
#define limit 1e18
#define mod 1000000007   
void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int power(int x, int y, int p){
	int res = 1;
	x = x % p;
	while (y > 0){
		if (y & 1)
			res = (res*x) % p;
		y = y>>1;
		x = (x*x) % p;
	}
	return res;
}
int fact[MAX5];
int factorial(){
	fact[0] = 1;
	for(int i = 1; i < MAX5; i++){
		fact[i] = fact[i-1]*i;
	}
}
int p[MAX5], q[MAX5];
void solve(){	
	int n, m;
	cin >> n;
	int cntpo = 0, cntpe = 0;
	for(int i = 0; i < n; i++){
		cin >> p[i];
		if(p[i]%2) cntpo++;
		else cntpe++;
	}
	cin >> m;
	int cntqo = 0, cntqe = 0;
	for(int i = 0; i < m; i++){
		cin >> q[i];
		if(q[i]%2) cntqo++;
		else cntqe++;
	}
	cout << cntpo*cntqo + cntpe*cntqe << endl;
}
	
signed main(){  
	flash;
	int t = 1;
		cin >> t;
	for(int tc = 1; tc <= t; tc++){
	//    goog(tc);
		solve();
	}
}