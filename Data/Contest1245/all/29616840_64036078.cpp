#include <bits/stdc++.h>
using namespace std;
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

typedef long long ll;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(int i = (a); i < (int) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl

//#define DEBUG

struct punto
{
	int x,y;
};

vector <punto> p(20005);
vector <ll> station(20005);
vector <ll> k(20005);

struct arista
{
   int n,m;
   ll peso;	
   bool operator<(const arista& x) const
   {
	   return peso < x.peso;
   }
};

ll ans=0;

vector <int> link(500005);
vector <int> size(500005);

void iniciar(int n)
{
	forn(i,n+1) link[i]=i;
	forn(i,n+1) size[i]=1;
}

int find(int x)
{
	if(x==link[x]) return x;
	return link[x]=find(link[x]);
}

bool same(int a, int b)
{
	return find(a)==find(b);
}

void unite(int a, int b)
{
	a=find(a); b=find(b);
	if(size[a]<size[b]) swap(a,b);
	size[a]+=size[b];
	link[b]=a;
}

vector <arista> Kruskal(int n, vector <arista> &v)
{
	sort(all(v));
	iniciar(n);
	vector <arista> lista;
	for(auto u : v)
	{
		if(same(u.n,u.m) == false) {unite(u.n,u.m); lista.pb(u); ans+=u.peso;}
	}
	return lista;
}


int main()
{ 	
	FIN;
	
	#ifdef DEBUG
		freopen("test_1.txt", "r", stdin);
	#endif
	
	int n;
	cin >> n;
	vector <arista> v;
	forn(i,n)
	{
		cin >> p[i].x >> p[i].y;
	}
	forn(i,n) 
	{
		cin >> station[i];
		arista aux;
		aux.n=0; aux.m=i+1; aux.peso=station[i];
		v.pb(aux);
	}
	forn(i,n) cin >> k[i];
	
	forn(i,n)
	{
		for(int j=1; j<n; j++)
		{
			ll peso=(k[i]+k[j])*(abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y));
			arista aux;
			aux.n=i+1; aux.m=j+1; aux.peso=peso;
			v.pb(aux);
		}
	}
	vector <arista> lista=Kruskal(n+1,v);
	vector <int> w;
	vector < pair<int,int> > z;
	for(auto u : lista) 
	{
		if(u.n == 0) w.pb(u.m);
		else z.pb(mp(u.n,u.m));
	}
	cout << ans << endl;
	cout << w.size() << endl;
	if(w.size()!=0) for(auto u : w) cout << u << " ";
	cout << endl;
	cout << z.size() << endl;
	for(auto u : z) cout << u.first << " " << u.second << endl;
    return 0;
}
