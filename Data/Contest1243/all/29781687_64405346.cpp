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
vector<int> v[Sz];

ll S[Sz];

vector<pii> g[Sz];

int pr[Sz];
 

  map <ll, pii> pos;

int main()
{
  # ifdef Local
    //localInput();
  # endif
  Read_rap();
  int k;
  cin >> k;
  ll sum = 0;

  for (int i = 0; i < k; i++) {
  	int n;
  	cin >> n;
  	v[i].resize(n);
  	for (int j =0; j < n; j++)
  	{
  		cin >> v[i][j];
  		sum += v[i][j];
  		pos[v[i][j]] = mp (i,j);
  		S[i] += v[i][j];
  	}
  }
  if (sum % k) {
  	cout << "No";
  	return 0;
  }
  ll E = sum/k;
  
  bool u2[15];
  bool used[15][5000];
  for (int i = 0; i < 15; i++)
  	for (int j = 0; j < 5000; j++)
  		used[i][j] = 0;
  for (int i = 0; i < 15; i++)
  	u2[i] = 0;
  for (int i = 0; i < k; i++) {
  	
  	for (int j = 0; j < v[i].size(); j++) {
  		int mask = 0;
  		vector<pii> c;
  		int a = i, b = j;

  		while (true) {
  			u2[a] = 1;
  			mask |= (1<<a);
  			c.pb(mp(a,b));
  			ll pr = E-(S[a]-v[a][b]);

  			if (!pos.count(pr)) {
  				mask = 0;
  				break;
  			}
  			
  			tie(a,b) = pos[pr];
  			if (u2[a])
  				break;
  		}
  		if (a == i && b == j && mask)
  			g[mask] = c;
  		
  		for (auto x : c)
  			u2[x.f] = 0;
  	}
  }
  for (int mask = 0; mask < (1<<k); mask++) {
  	pr[mask] = -1;
  	if (g[mask].size())
  		pr[mask] = 0;
  	for (int s = mask; s; s = ((s-1) & mask)) {
  		
  		if (pr[s]!= -1 && g[mask^s].size()) {
  			pr[mask] = s;
  		}
  	}
  }
  int all = (1<<k) - 1;
  if (pr[all] ==  -1) {
  	cout << "No";
  }
  else {
  	int V = all;
  	vector<pii> ans(k);

  	while (V) {
  		int mask = (pr[V] ^ V);
  		for (int i = 0; i < g[mask].size(); i++) {
  		
  			int j = (i == 0 ? g[mask].size()-1 : i-1);
  			int x, y;
  			tie(x, y) = g[mask][i];
  			ans[x] = mp (g[mask][j].first,v[x][y]);
  		}
  		V = pr[V];
  	}
  	cout << "Yes" << endl;
  	for (int i = 0; i < k; i++)
  		cout << ans[i].second << ' ' << ans[i].first+1 << endl;
}
 
 
  return 0;
}