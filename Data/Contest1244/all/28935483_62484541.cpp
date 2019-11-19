#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl;
#define ddebug(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#else
#define debug(x);
#define ddebug(x, y);
#endif

#define ld long double
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define FORD(i, a, b) for(int i = (int)(a); i > (int)(b); i--)
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define sq(a) ((a) * (a))
#define vi vector <int>
#define pii pair <int, int>
#define vl vector <long long>
#define pll pair <long long, long long>
#define MMIN(a, b) a = min(a, b)
#define MMAX(a, b) a = max(a, b)

template <typename T>  
ostream& operator <<(ostream &out, vector<T> a){ 
    FOR(i, 0, sz(a)) 
        if(i != sz(a) - 1)
            out << a[i] << " ";   
        else
            out << a[i] << endl;   
    return out; 
} 
template <typename T1, typename T2> 
istream& operator >>(istream &in, pair<T1, T2> & a){
    in >> a.fi >> a.se;
    return in;
}

template <typename T1, typename T2> 
ostream& operator <<(ostream & out, pair<T1, T2> & a){
    out << a.fi << " " << a.se;
    return out;
}

struct fastio{
    fastio(){
#ifndef LOCAL
        string filename = "";
        if(filename.size()){
            string inp = filename + ".in";
            string out = filename + ".out";
            freopen(inp.c_str(), "r", stdin);
            freopen(out.c_str(), "w", stdout);
        }
#endif
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout << showpoint;
        cout << setprecision(12);
        cout << fixed;    

        cerr << showpoint;
        cerr << setprecision(3);
        cerr << fixed;    
    }
}_____;

const int MAX = 2e6 + 10;
const ll INF = 1e18 + 10;
const ld EPS = 1e-8;
const ll MOD = 1e9 + 7;    
           

int n;
vi e[MAX];
ll c[MAX][3];
int color[MAX];
bool used[MAX];
int ord[] = {0, 1, 2};
ll dfs(int v, int col){
	used[v] = true;    
	col %= 3;
	color[v] = ord[col];
	ll res = c[v][ord[col]];	
	FOR(i, 0, sz(e[v]))
		if(!used[e[v][i]])
			res += dfs(e[v][i], col + 1);
	return res;
}
void solve(){  
	cin >> n;
	FOR(i, 0, 3)
		FOR(j, 0, n)
			cin >> c[j + 1][i];     
	FOR(i, 0, n - 1){
		int u, v;
		cin >> u >> v;
		e[u].pb(v);
		e[v].pb(u);
		if(sz(e[u]) >= 3 && n != 3){
			cout << -1 << endl;
			return;
		}
		if(sz(e[v]) >= 3 && n != 3){
			cout << -1 << endl;
			return;
		}
	}
	if(n == 3){
		int tmp[] = {0, 1, 2};
		int for_ans[] = {0, 1, 2};
		ll ans = INF;
		do{
			if(c[1][tmp[0]] + c[2][tmp[1]] + c[3][tmp[2]] < ans){
				ans = c[1][tmp[0]] + c[2][tmp[1]] + c[3][tmp[2]];
				FOR(j, 0, 3)
					for_ans[j] = tmp[j];
			}

		}while(next_permutation(tmp, tmp + 3));
		cout << ans << endl;
		FOR(j, 0, 3)
			cout << for_ans[j] + 1 << " ";
		cout << endl;
		return;
	}
	ll ans = INF;
	int for_ans = -1;
	int for_ans_ord[] = {0, 1, 2};
	int root = -1;
	FOR(i, 1, n + 1)
		if(sz(e[i]) == 1){
			root = i;
			break;
		}
	debug(root);
	do{
		FOR(st, 0, 3){
			fill(used, used + n + 1, false);
			if(dfs(root, st) < ans){
				fill(used, used + n + 1, false);
				ans = dfs(root, st);
				for_ans = st;
				FOR(i, 0, 3)
					for_ans_ord[i] = ord[i];
			}
		}
	}while(next_permutation(ord, ord + 3));
	cout << ans << endl;
	FOR(i, 0, 3)
		ord[i] = for_ans_ord[i];
	fill(used, used + n + 1, false);
	dfs(root, for_ans);
	FOR(i, 1, n + 1)
		cout << color[i] + 1 << " ";
	cout << endl;               
}

             
int main(){ 
    #ifdef LOCAL
    clock_t beg = clock(); 
    #endif
    solve();
    #ifdef LOCAL
    clock_t end = clock();
    ld elapsed_secs = (ld)(end - beg) / CLOCKS_PER_SEC;
    debug(elapsed_secs);
    #endif
    return 0;
}