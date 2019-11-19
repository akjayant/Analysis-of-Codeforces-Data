#include <bits/stdc++.h>
#define sqr(a) ((a)*(a))
#define rsz resize
#define forr(i,a,b) for(int i=(a);i<(b);i++)
#define forn(i,n) forr(i,0,n)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define forall(it,v) for(auto it=v.begin();it!=v.end();it++)
#define sz(c) ((int)c.size())
#define zero(v) memset(v, 0, sizeof(v))
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define fst first
#define snd second
#define PI 3.1415926535897932384626

using namespace std;

typedef unsigned long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main()
{
	#ifdef REJUNTE
	freopen("input.in","r",stdin);
	//freopen("output.out","w",stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n,k,x;
	map<ll,ll> m;
	cin >> n >> k;
	forn(i,n)
	{
		cin >> x;
		m[x]++;
	}
	while(m.size()>1 && k>0)
	{
		if(m.begin()->snd <= m.rbegin()->snd)
		{
			ll val=m.begin()->fst,cant=m.begin()->snd;
			m.erase(m.begin());
			ll nxtval=m.begin()->fst;
			if((nxtval-val)*cant<=k)
			{
				m.begin()->snd+=cant;
				k-=(nxtval-val)*cant;
			}
			else
			{
				m[val+k/cant]=1;
				k=0;
			}
		}
		else
		{
			ll val=m.rbegin()->fst,cant=m.rbegin()->snd;
			m.erase(m.rbegin()->fst);
			ll nxtval=m.rbegin()->fst;
			if((val-nxtval)*cant<=k)
			{
				m.rbegin()->snd+=cant;
				k-=(val-nxtval)*cant;
			}
			else
			{
				m[val-k/cant]=1;
				k=0;
			}
		}
	}
	cout << m.rbegin()->fst-m.begin()->fst << '\n';
	return 0;
}