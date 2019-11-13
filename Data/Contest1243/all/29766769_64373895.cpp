#include <bits/stdc++.h>
#define N 1000005
#define ll long long int 	
#define MP make_pair
#define pb push_back
#define ppb pop_back
#define sp " "
#define endl "\n"
#define fi first
#define se second
#define ii pair<int,int>
#define lli pair<ll,ll>
#define fast cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(false)
#define fast2 freopen ("badhair.gir","r",stdin);freopen ("badhair.cik","w",stdout);
#define mod 1000000007
#define fs(x,y) for(ll i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(ll i=x;i<=y;i++)
#define INF 1000000000005
using namespace std;

ll n,m,ar[N],sum,t;



int main()
{
	fast;
	cin>>t;
	while(t--)
	{
		cin>>n;
		fs(ar,n);
		sort(ar+1,ar+n+1);
		ll mk=0;
		for(int i=1;i<=n;i++)
		{
			ll k=min(ar[i],n-i+1);
			// if(ar[i]<=n-i+1)
				mk=max(mk,k);
		}
		cout<<mk<<endl;
	}

}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/