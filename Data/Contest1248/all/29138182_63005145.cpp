#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// #include <boost/multiprecision/cpp_int.hpp> 

#define gc getchar//_unlocked
#define pc putchar//_unlocked
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define pp pair<int,int>
#define ppl pair<ll,ll>
#define bigint boost::multiprecision::cpp_int
#define finp ios_base::sync_with_stdio(0);cin.tie(0);
#define bc __builtin_popcountll
#define afor(i,a,b) for(int i=a;i<=b;++i)
#define bfor(i,a,b) for(int i=a;i>=b;--i)
#define vi vector<int>
#define vpp vector<pp>
#define vll vector<ll>
#define fr first
#define se second

using namespace std;
using namespace __gnu_pbds;

char putnb[20];
void putn(ll n) {if(!n)pc('0');if(n<0)pc('-'),n=0-n;int pi=0;while(n)putnb[pi++]=(n%10)+'0',n/=10;while(pi)pc(putnb[--pi]);}
void sci(int *x) {register char c = gc();*x = 0;for(; (c<48)||(c>57);c = gc());for(; (c>47)&&(c<58);c = gc())*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);}
void scll(ll *x)  {register char c = gc();*x = 0;for(; (c<48)||(c>57);c = gc());for(; (c>47)&&(c<58);c = gc())*x =  (ll)((((*x)<<1) + ((*x)<<3)) + c - 48);}
ll fp(ll a,ll b,ll c) {if(b==0)return 1%c; if(b==1)return a%c; ll ret=fp(a,b/2,c); ret=(ret*ret)%c; if(b&1)ret=(ret*a)%c; return ret;}

const ll mod=1e9 +7;
const ll mod2=1999999973;
const ll inf=1e18;
const int infs=1e9 + 1000;
const int N=1000000;
const long double PI = acos(-1);

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n,m;
//ll c[N + 5];
//int a[N + 5];
bool vis[N + 5];

vi adj[N + 5];
vi adj2[N + 5];
vi topo;
//ll cst[N + 5];
vi comps[N + 5];
int cid[N + 5];


void dfs1(int pos)
{
  if(vis[pos])return;
  vis[pos] = true;
  for(auto i:adj[pos])
  {
    dfs1(i);
  }
  topo.pb(pos);
}



void dfs2(int pos,int cmp)
{
  if(vis[pos])return;
  cid[pos] = cmp;
  comps[cmp].push_back(pos);
  vis[pos] = true;
 // cst[cmp] = min(cst[cmp] ,  c[pos]);
  for(auto i:adj2[pos])
  {
    dfs2(i,cmp);
  }
}

//set<int> adj3[N + 5];
int in[N + 5];

int main()
{
  finp;
  int t;
  cin>>t;
  while(t--)
  {
	   cin>>n>>m;
	  afor(i,1,n)vis[i] = false,adj[i].clear(),adj2[i].clear(),comps[i].clear();
	  afor(i,1,m)
	  {
	    int u,v;
	    cin>>u>>v;
	    if(u == v)continue;
	    adj[u].pb(v);
	    adj2[v].pb(u);
	  }
	  
	  afor(i,1,n)
	  {
	    dfs1(i);
	  }
	  afor(i,1,n)vis[i] = false;

	  int nn = 0;
	  while(topo.size())
	  {
	    int x = topo.back();
	    topo.pop_back();
	    if(vis[x])continue;
	    ++nn;
	    //cst[nn] = inf;
	    dfs2(x,nn);
	  }

	  afor(i,1,nn)in[i] = 0;

	  afor(i,1,n)
	  {
	    for(auto j:adj[i])
	    {
	      if(cid[i] != cid[j])
	      {
	        in[cid[i]]++;
	      }
	    }
	  }

	  int cand = -1;
	  afor(i, 1, nn)if(in[i]==0)cand = i;



	  if(nn == 1)cout<<"No\n";
	  else
	  {
	  	cout<<"Yes\n";
	  	vi jury, part;
	  	assert(cand != -1);
	  	afor(i, 1, nn)
	  	{
	  		if(i == cand)
	  		{
	  			for(auto j:comps[i])jury.push_back(j);
	  		}
	  		else
	  		{
	  			for(auto j:comps[i])part.push_back(j);
	  		}
	  	}
	  	cout<<jury.size()<<" "<<part.size()<<"\n";
	  	for(auto i:jury)cout<<i<<" "; cout<<"\n";
	  	for(auto i:part)cout<<i<<" "; cout<<"\n";
	  }
}
  
return 0;
}