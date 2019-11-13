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

int n, ans, in[1001];
int main(){
	fastio;
	int q;
	cin>>q;
	while(q--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>in[i];
		}
		sort(in+1,in+n+1);
		ans=0;
		for(int i=n;i>=1;i--){
			ans = max(ans, min(n-i+1,in[i]));
		}
		cout<<ans<<"\n";
	}
}