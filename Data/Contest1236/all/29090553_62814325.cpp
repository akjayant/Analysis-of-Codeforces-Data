/*
 _     _                             
| |__ | |__   __ _  __ _ _   _  __ _ 
| '_ \| '_ \ / _` |/ _` | | | |/ _` |
| |_) | | | | (_| | (_| | |_| | (_| |
|_.__/|_| |_|\__,_|\__, |\__, |\__,_|
                   |___/ |___/       
*/
#include<bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define ppb         pop_back
#define	endl		'\n'
#define mii         map<ll int,ll int>
#define msi         map<string,ll int>
#define mis         map<ll int, string>
#define mpi         map<pair<ll int,ll int>,ll int>
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define vs          vector<string>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define what_is(x)  cerr << #x << " is " << x << endl;
using namespace std;
 
#define N  100005

vi vx[N];

vi vy[N];

 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
	// cin>>TESTS;
	while(TESTS--)
	{
		ll int n,m,k;
		cin>>n>>m>>k;
		for(ll int i=1;i<=k;i++)
		{
			ll int x,y;
			cin>>x>>y;
			vx[x].pb(y);
			vy[y].pb(x);
		}
		for(ll int i=0;i<N;i++)
		{
			vx[i].pb(0);
			vx[i].pb(N);
			vy[i].pb(0);
			vy[i].pb(N);
		}
		for(ll int i=1;i<=max(n,m);i++)
		{
			sort(all(vx[i]));
			sort(all(vy[i]));
		}
		ll int xb1=-1,xb2=n+1;
		ll int yb1=-1,yb2=m+1;
		ll int x=1,y=1;
		ll int dir=1;
		ll int cnt=0;
		while(true)
		{
			if(!(xb1<x&&x<xb2&&yb1<y&&y<yb2)) break;
			if(dir==1)
			{
				ll int idx=lower_bound(all(vx[x]),y)-vx[x].begin();
				ll int tmpy=vx[x][idx];
				tmpy=min(tmpy,yb2);
				if(tmpy==y) break;
				cnt+=tmpy-y;
				x=x+1;
				y=tmpy-1;
				dir=2;
				yb2=y+1;
				xb1=x-1;
			}
			else if(dir==2)
			{
				ll int idx=lower_bound(all(vy[y]),x)-vy[y].begin();
				ll int tmpx=vy[y][idx];
				tmpx=min(tmpx,xb2);
				if(tmpx==x) break;
				cnt+=tmpx-x;
				x=tmpx-1;
				y=y-1;
				dir=3;
				xb2=x+1;
				yb2=y+1;
			}
			else if(dir==3)
			{
				ll int idx=upper_bound(all(vx[x]),y)-vx[x].begin();
				idx--;
				ll int tmpy=vx[x][idx];
				tmpy=max(tmpy,yb1);
				if(tmpy==y) break;
				cnt+=y-tmpy;
				x=x-1;
				y=tmpy+1;
				dir=4;
				yb1=y-1;
				xb2=x+1;
			}
			else
			{
				ll int idx=upper_bound(all(vy[y]),x)-vy[y].begin();
				idx--;
				ll int tmpx=vy[y][idx];
				tmpx=max(tmpx,xb1);
				if(tmpx==x) break;
				cnt+=x-tmpx;
				x=tmpx+1;
				y=y+1;
				dir=1;
				xb1=x-1;
				yb1=y-1;
			}
		}
		ll int nonvis=n*m-k-cnt;
		if(!nonvis) cout<<"Yes";
		else cout<<"No";
	}
	return 0;
}