#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define FER(i,a,b) for(ll i = ll(a); i < ll(b); ++ i)
#define IFR(i,a,b) for(ll i = ll(a); i >= ll(b); -- i)
#define all(v) (v).begin(),(v).end()
#define mp make_pair
#define ff first
#define ss second
#define tm1 ff
#define tm2 ss.ff
#define tm3 ss.ss
#define fill(x,v) memset(x,v,sizeof(x))
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sqr(x) (x)*(x)
#define bas 987625403
typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> tri;
typedef vector<ll> vi;
typedef vector<ii> vii;
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)

template<typename t> void fff(const char *x, t&& val1){
	cout << x << " : " << val1 << endl;
}

template<typename t1, typename... t2> void fff(const char *x, t1&& val1, t2&&... val2){
	const char *xd = strchr(x + 1, ',');
	cout.write(x, xd -x) << " : " << val1 << " | ";
	fff(xd + 1, val2...);
}

int n;
string s, p;
vector<ii> ans;
map<char, int> cnt;

void traer(char c, int posp){
	FER(i, posp + 1, n){
		if(s[i] == s[posp]){
			ans.pb(mp(i, posp));
			swap(s[i], p[posp]);
			return;
		}
	}
	FER(i, posp + 1, n){
		if(p[i] == p[posp]){
			ans.pb(mp(posp, i));
			swap(s[posp], p[i]);
			return;
		}
	}
	FER(i, posp + 1, n){
		if(s[posp] == p[i]){
			ans.pb(mp(n - 1, i));
			swap(s[n - 1], p[i]);
			ans.pb(mp(n - 1, posp));
			swap(s[n - 1], p[posp]);
			return;
		}
	}
	assert(false);
}

int main(){
	fastio;
	int t; cin >> t;
	while(t --){
		ans.clear();
		cnt.clear();
		cin >> n;
		cin >> s >> p;
		FER(i, 0, sz(s)) cnt[s[i]] ++;
		FER(i, 0, sz(p)) cnt[p[i]] ++;
		int gg = 0;
		for(auto x: cnt){
			if(x.ss % 2) {
				cout << "No" << endl;
				gg ++; break;
			}
		}
		if(gg) continue;
		FER(i, 0, n){
			if(s[i] != p[i]){
				traer(s[i], i);	
			}
		}
		if(sz(ans) > 2 * n) cout << "No" << endl;
		else{
			assert(s == p);
			cout << "Yes" << endl;
			cout << sz(ans) << endl;
			FER(i, 0, sz(ans)){
				cout << ans[i].ff + 1 << " " << ans[i].ss + 1 << endl;
			}
		}
	}
	return 0;
}
