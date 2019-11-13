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

int n;
string a, b;
vector<int> flag;
int main(){
	fastio;
	int q;
	cin>>q;
	while(q--){
		cin>>n;
		cin>>a;
		cin>>b;
		flag.clear();
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]) flag.pb(i);
		}
		if(flag.size()==0) {cout<<"Yes\n";continue;}
		if(flag.size()==1||flag.size()>=3) {cout<<"No\n";continue;}
		else{
			int x = flag[0];
			int y = flag[1];
			if(a[x]==a[y]&&b[x]==b[y]) cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
}