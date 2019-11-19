# include <bits/stdc++.h>
 
# define f first
# define s second
# define mp make_pair
// everything goes according to my plan
# define pb push_back
# define sz(a) (int)(a.size())
# define vec vector
// shimkenttin kyzdary, dzyn, dzyn, dzyn...
# define y1    Y_U_NO_y1
# define left  Y_U_NO_left
# define right Y_U_NO_right
 
# ifdef Local
# define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
# else
# define debug(...) (__VA_ARGS__)
# define cerr if(0)cout
# endif
 
using namespace std;
 
typedef pair <int, int> pii;
typedef long long ll;
typedef long double ld;
 
const int Mod = (int)1e9 + 7;
const int MX = 1073741822;
const ll MXLL = 4e18;
const int Sz = 1110111;
// a pinch of soul
inline void Read_rap () {
  ios_base :: sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
}
inline void randomizer3000 () {
  unsigned int seed;
  asm ("rdtsc" : "=A"(seed));
  srand (seed);
}
void files (string problem) {
  if (fopen ((problem + ".in").c_str(),"r")) {
    freopen ((problem + ".in").c_str(),"r",stdin);
    freopen ((problem + ".out").c_str(),"w",stdout);
  }
}
void localInput(const char in[] = "s") {
  if (fopen (in, "r")) {
    freopen (in, "r", stdin);
  }
  else
    cerr << "Warning: Input file not found" << endl;
}
int n, m;
vector<int> g[Sz];

set <int> u;

bool used[Sz];

void dfs (int v) {
	used[v] = 1;
	u.erase(v);
	int prev = 0;
	g[v].pb(n+1);
	for (int to : g[v]) {
		while (true) {
			auto it = u.upper_bound (prev);
			if (it != u.end() && prev < *it && *it < to) {
				dfs (*it);
			}
			else
				break;
		}
		prev = to;
	}
}

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
  	int a, b;
  	cin >> a >> b;
  	g[a].pb(b);
  	g[b].pb(a);
  }
  for (int i = 1; i <= n; i++)
  {
  	sort (g[i].begin(), g[i].end());
  	u.insert (i);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
  	if (!used[i]) {
  		dfs (i);
  		cnt++;
  	}
  }
  cout << cnt-1;

  return 0;
}