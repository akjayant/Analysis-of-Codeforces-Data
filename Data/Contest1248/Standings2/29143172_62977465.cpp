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

// I will come in top 100 of this round.
// For sure.
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		ll n  , m, x; cin >> n;
		ll even = 0 , odd = 0;
		for(int i = 0;i < n;i++){
			cin >> x;
			if(x%2 == 0)
				even++;
			else
				odd++;
		}
		cin >> m;
		ll even1 = 0 , odd1 = 0;
		for(int i = 0;i < m;i++){
			cin >> x;
			if(x%2 == 0)
				even1++;
			else
				odd1++;
		}
		cout << even1*even + odd1*odd << '\n';
	}
	return 0;
}



















