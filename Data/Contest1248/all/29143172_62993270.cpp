#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";}

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
typedef long long ll;
typedef double ld;
#define pll pair<ll,ll>
#define pii pair<int, int>
#define pb push_back
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define I insert
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define vpii vector<pii>
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()

const ll Mod = 1e9 + 7;
const int N = 1e5 + 7;

ll dp[2][N];




int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll n , m; cin >> n >> m;

	if(n == 1 && m == 1){
		cout << 2 << endl;
		return 0;
	}

	dp[0][2] = 2;
	dp[1][2] = 2;
	// 0 denotes different
	// 1 denotes same
	

	for(int i = 3;i < N ;i ++){
		dp[0][i] = dp[0][i-1] + dp[1][i-1];
		dp[1][i] = dp[0][i-1];
		if(dp[0][i] >= Mod)
			dp[0][i] -= Mod;
		if(dp[1][i] >= Mod)
			dp[1][i] -= Mod;
	}
	if(m == 1)
		swap(n , m);
	if(n == 1){
		cout << (dp[0][m] + dp[1][m])%Mod << endl;
		return 0;
	}
	

	ll ans = dp[0][m] + dp[1][m];
	ans %=Mod;
	ll atleastone = ans - 2;
	if(atleastone < 0)
		atleastone += Mod;
	
	ll norep = 2;
	ll final = atleastone + (dp[0][n] + dp[1][n]);
	final %= Mod;
	cout << final << endl;







	return 0;
}









