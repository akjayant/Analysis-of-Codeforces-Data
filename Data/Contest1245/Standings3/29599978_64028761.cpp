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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
void pt(T v){cout<<v;}
template <typename T>
void pt(vector<T> v){for(auto &i:v)pt(i),cout<<" ";}
template <typename T1, typename T2>
void pt(map<T1, T2> v){for(auto &i:v)pt(i.first),cout<<"->",pt(i.second),cout<<"\n";}
template <typename T>
void pt(set<T> v){for(auto &i:v)pt(i);cout<<" ";}

char putnb[20];
void putn(ll n) {if(!n)pc('0');if(n<0)pc('-'),n=0-n;int pi=0;while(n)putnb[pi++]=(n%10)+'0',n/=10;while(pi)pc(putnb[--pi]);}
void sci(int *x) {register char c = gc();*x = 0;for(; (c<48)||(c>57);c = gc());for(; (c>47)&&(c<58);c = gc())*x = (int)((((*x)<<1) + ((*x)<<3)) + c - 48);}
void scll(ll *x)  {register char c = gc();*x = 0;for(; (c<48)||(c>57);c = gc());for(; (c>47)&&(c<58);c = gc())*x =  (ll)((((*x)<<1) + ((*x)<<3)) + c - 48);}
ll fp(ll a,ll b,ll c) {if(b==0)return 1%c; if(b==1)return a%c; ll ret=fp(a,b/2,c); ret=(ret*ret)%c; if(b&1)ret=(ret*a)%c; return ret;}

const ll mod=1e9 +7;
const ll mod2=1999999973;
const ll inf=1e18;
const int infs=1e9 + 1000;
const int N = 2000;
const long double PI = acos(-1);

int id[N + 5];
ll ans;
int n;
ll x[N + 5];ll y[N + 5];
int find(int p) {
	int root = p;
	while(root != id[root])root = id[root];
	/*while(p != root) {
		int q = id[root];
		id[p] = root;
		p = q;
	}*/
	return root;
}
ll c[N + 5];
ll k[N + 5];
ll dist[N + 5][N + 5];
//vi id2[N + 5];
set<int> ps;
vpp edg;
void merge(int u, int v) {
	int uu = find(u);
	int vv = find(v);
	ll toadd = (k[u] + k[v]) * dist[u][v];

	if (uu == vv) {
		return;
	}
	
	//ll toadd = (k[u] + k[v]) * dist[u][v];
	toadd-= max(c[uu], c[vv]);
	if(toadd < 0){
		edg.pb({u, v});
		ans+= toadd;
		if(c[uu] <= c[vv])id[vv] = uu;
		else id[uu] = vv;
	}
}



int main()
{
  finp;
  cin>>n;
  afor(i, 1, n) cin >> x[i] >> y[i];

  afor(i, 1, n)afor(j, 1, n)dist[i][j] = llabs(x[i] - x[j]) + llabs(y[i] - y[j]);

  afor(i, 1, n) cin >> c[i], ans+= c[i];
  afor(i, 1, n) cin >> k[i], id[i] = i;

  vector<pair<ll, pp>> v;
  afor(i, 1, n)afor(j, i + 1, n) {
  	ll toadd = (k[i] + k[j]) * dist[i][j];
  	v.pb({toadd, {i, j}});
  }
  sort(v.begin(), v.end());
  for(auto i:v) {
  	merge(i.se.first, i.se.se);
  }

  cout<<ans<<"\n";
  afor(i, 1, n)ps.insert(find(i));
  cout<<ps.size()<<"\n";
  for(auto i:ps)cout<<i<<" ";
  cout<<"\n";
  cout<<edg.size()<<"\n";
  for(auto i:edg)cout<<i.fr<<" "<<i.se<<"\n";
 
return 0;
}