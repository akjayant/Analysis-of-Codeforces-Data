#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include <map>
#include <list>
#include<set>
using namespace std;

#define FOR(n) for(int i=0;i<n;++i)
#define FORj(n) for(int j=0;j<n;++j)
#define pb push_back
#define ll long long
#define vecI vector<int> 
#define vecII vector<vector<int>>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define max4(a,b,c,d) max(max3(a,b,c),d)
ll mas[2001][2001] = { 0 };
ll x[2000];
ll y[2000];
ll c[2000];
ll k[2000];
vector<pair<ll,pll>>s;
vecI graf[2001];
bool sv[2001][2001] = { 0 };
bool electro[2001];
bool r[2001][2001];
int main()
{
	ll n,p,q,otv=0,a1,b1,konec,h1,h2,v=0;
	cin >> n;
	konec = n + 1;
	FOR(n)cin >> x[i] >> y[i];
	FOR(n)cin >> c[i];
	FOR(n)cin >> k[i];
	FOR(n)
	{
		mas[0][i + 1] = c[i];
		mas[i + 1][0] = c[i];
	}
	FOR(n)
		FORj(n)
		mas[i+1][j+1] = (k[i] + k[j])*(abs(x[i] - x[j]) + abs(y[i] - y[j]));
	FOR(n+1)
		FORj(n+1)
			if(i<j)
		s.pb(pair<ll,pll>(mas[i][j],pll(i,j)));
	sort(s.begin(), s.end());
	FOR(n+1)graf[i].pb(i);
	FOR(size(s))
	{
		if (konec == (n + 1)*(n + 1))break;
		p = s[i].second.first;
		q = s[i].second.second;
		if (sv[p][q] == 1)continue;
		otv += s[i].first;
		if (p == 0)electro[q] = 1;
		else if (q == 0)electro[p] = 1;
		else
		{
			r[p][q] = 1;
			r[q][p] = 1;
		}
		h1 = size(graf[p]);
		h2 = size(graf[q]);
		for(int a=0;a<h1;++a)
			for (int b = 0; b < h2; ++b)
			{
				a1 = graf[p][a];
				b1 = graf[q][b];
				graf[a1].pb(b1);
				graf[b1].pb(a1);
				sv[a1][b1] = 1;
				sv[b1][a1] = 1;
				konec += 2;
			}
    }
	cout << otv << endl;
	FOR(n + 1)if (electro[i])v++;
	cout << v << '\n';
	FOR(n + 1)if (electro[i])cout << i << ' ';
	cout << endl<<n - v << endl;
	FOR(n + 1)
		FORj(i)
		if (r[i][j])cout << i << ' ' << j << '\n';
}