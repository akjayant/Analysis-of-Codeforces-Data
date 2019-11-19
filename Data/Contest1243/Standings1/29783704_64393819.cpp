#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define fopen freopen("input.txt", "r", stdin)
#define pb push_back
#define prec(a) cout<<fixed;cout.precision(a);
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll INF = 9e18;
const int inf = 2e9;
template<class T>
void pr(T t) {cout << t << " ";}
template<class T, class ...Args>
void pr(T a, Args ...args) {cout << a << " ";pr(args...);}
template<class ...Args>
void prl(Args ...args) {pr(args...);cout << endl;}

ll n;
int main(){
	fastio;
	cin>>n;
	ll ans = n;
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ans = __gcd(ans, i);
			ans = __gcd(ans, n/i);
		}
	}
	cout<<ans;

}