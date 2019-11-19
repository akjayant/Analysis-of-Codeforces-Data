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
#define fs(x,y) for(int i=1;i<=y;i++) cin>>x[i]
#define fo(i,x,y) for(int i=x;i<=y;i++)
#define INF 1000000000005
using namespace std;

ll n,m,ar[N],sum,tutl[N],tutr[N];



int main()
{
	fast;
	cin>>n>>m;
	fs(ar,n);
	sort(ar+1,ar+n+1);
	// fo(i,1,n)
	// cout<<ar[i]<<sp;
	// cout<<endl;
	for(int i=n;i>=1;i--)
	{
		tutl[i]=1;
		if(ar[i]==ar[i+1])
			tutl[i]=tutl[i+1]+1;
	}
	for(int i=1;i<=n;i++)
	{
		tutr[i]=1;
		if(ar[i]==ar[i-1])
			tutr[i]=tutr[i-1]+1;
	}
	int l=1,r=n;
	sum=ar[n]-ar[1];
	while(l<r && m && sum>0)
	{
		int x=l+tutl[l]-1;
		int y=n-r+tutr[r];
		if(x>m && y>m)
			break;
		// cout<<l<<sp<<r<<sp<<m<<endl;
		if(x<=y)
		{
			ll q=m/x;
			ll t=min(q,ar[l+tutl[l]]-ar[l]);
			sum-=t;
			m-=t*x;
			if(t==ar[l+tutl[l]]-ar[l])
				l=l+tutl[l];
		}	
		else
		{
			ll q=m/y;
			ll t=min(q,ar[r]-ar[r-tutr[r]]);
			sum-=t;
			m-=t*y;
			if(t==ar[r]-ar[r-tutr[r]])
				r=r-tutr[r];
		}

	}
	// cout<<endl;
	cout<<sum;
}



/*     cd onedrive\desktop\kod
cls

Sinav:21-22 aralik
Aciklama: Muhtemelen 25 aralik
*/