#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ull mod = 1e9 + 7;
#define REP(i,n) for(int i=0;i<(int)n;++i)

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

ll c[3][101010];
vector<ll> G[101010];
vector<ll> col(101010);

ll dfs(ll now, ll par, ll depth, vector<ll> &pat){
	ll res = 0;
	res += c[pat[depth%3]][now];
	col[now] = pat[depth%3];
	REP(i, G[now].size()){
		ll next = G[now][i];
		if(next==par) continue;
		res += dfs(next, now, depth+1, pat);
	}
	return res;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    REP(i, 3){
    	REP(j, n){
    		cin >> c[i][j];
    	}
    }

    REP(i, n-1){
    	ll u, v;
    	cin >> u >> v;
    	u--, v--;
    	G[u].push_back(v);
    	G[v].push_back(u);
    }

    ll idx = -1;
    REP(i, n){
    	int deg = G[i].size();
    	if(deg>=3){
    		cout << -1 << endl;
    		return 0;
    	}
    	if(deg==1) idx = i;
    }

    ll res = (1ll<<60);
    vector<ll> perm2 = {0, 1, 2};
    vector<ll> last;
	bool flag = true;
	while(flag){
		//vprint(perm2);
		ll tmp = dfs(idx, -1, 0, perm2);

		//cout << perm2 << endl;

		if(res > tmp){
			res = tmp;
			last = perm2;
		}
		flag= next_permutation(perm2.begin(), perm2.end());
	}
	//cout << last << endl;
	dfs(idx, -1, 0, last);
	cout << res << endl;
	REP(i, n) cout << col[i]+1 << " ";
	cout << endl;
    return 0;
}