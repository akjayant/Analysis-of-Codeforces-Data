#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

typedef double d;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INIT ios_base::sync_with_stdio(false); cin.tie(0),cout.tie(0)
#define endl '\n'
#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ers erase
#define sz(c) ((int)(c).size())
#define all(x) (x).begin(),(x).end()
#define unique(x) (x).resize(unique(all(x))-(x).begin())
#define debug(_fmt,...) fprintf(stderr,"("#__VA_ARGS__ ") = (" _fmt")\n",__VA_ARGS__)

const d eps = 1e-12;

inline int sign(d x) { return x < -eps ? -1 : x > eps; }
inline int realcmp(d x, d y) { return sign(x-y); }
template<typename T> void na(vector<T>& a, int n) {a = vector<T>(n);for(T& i: a) cin >> i;}
template<typename T> void pv(vector<T>& a) { for(T& i: a) cout << i << ' '; cout << endl; }
template<typename T> vector<T> shrink(vector<T>& x) { vector<T> vals = x; sort(all(vals)); unique(vals); for(T& i: x) i = ub(all(vals), i) - vals.begin(); return vals; }

int N;

//~ testado en http://codeforces.com/contest/892/problem/E
struct UF
{
	int n;
	vector<int> root, r;
	vector<pii> ops;
	UF(int n)
	:root(n+1),r(n+1,1)
	{
		for(int i=1;i<=n;++i)root[i]=i;
	}
	
	int fs(int u)
	{
		while(root[u]!=u)u=root[u];
		return u;
	}
	bool js(int u,int v)
	{
		u=fs(u),v=fs(v);
		if(u==v)return false;
		if(r[u]<r[v])
			swap(u,v);
		
		ops.emplace_back(u,v);
		--N;
		r[u]+=r[v];
		root[v]=u;
		return true;
	}
	void rb(int steps)
	{ // rollback technique
		while(steps--)
		{
			pii cur=ops.back();
			
			r[cur.fr]-=r[cur.sc];
			root[cur.sc]=cur.sc;

			ops.pop_back();
		}
	}
};

const int MX = 1e5+7;

vector<int> g[MX];
void eadd(int u, int v)
{
  g[u].pb(v);
  g[v].pb(u);
}

int main()
{
  #ifdef OJUDGE
    //freopen("in","r",stdin);
  #endif
  INIT;
  
  int n, m;
  cin >> n >> m;
  
  N = n;
  UF uf1(n);
  for(int i=1;i<=m;++i)
  {
    int u, v;
    cin >> u >> v;
    eadd(u, v);
    uf1.js(u, v);
  }
  cerr  <<"No of comp: " << N << endl;
  
  if(N > 1) return !(cout << "0\n");
  
  set<int> MK;
  int ss = n;
  for(int i=1;i<=n;++i)
  {
    if(ss > sz(g[i]))
    {
      ss = sz(g[i]);
      
    }
    MK.ins(i);
  }
  
  if(ss == n-1) return !(cout << n-1 << "\n");
  //~ cerr << "mins: " << ss << endl;
  
  int ncomp = 0;
  for(int i=1;i<=n;++i)
  {
    if(MK.find(i) != MK.end())
    {
      //~ cerr << "found: " << i << endl;
      ++ncomp;
      queue<int> q;
      q.push(i);
      MK.ers(i);
      while(!q.empty())
      {
        int u = q.front();
        //~ cerr << u << endl;
        q.pop();
        vector<int> del;
        for(int v: g[u])
        {
          if(MK.find(v) != MK.end())
            del.pb(v);
        }
        
        for(int de: del) MK.ers(de);
        
        for(int j: MK) q.push(j);
        MK.clear();
        
        for(int de: del) MK.ins(de);
        
      }
    }
  }
  
  cout << ncomp - 1 << endl;
  
  return 0;
}

#warning you will remember this, overflow is there, though you might not see it ...

