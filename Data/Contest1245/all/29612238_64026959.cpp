#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ld long double
#define f(i,x,n) for(int i=x;i<n;i++)
#define int long long
#define mod 1000000007
#define endl "\n"
const int INF = 1e18;
void fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
int c[20001],k[20001],ans=0;
int32_t main() 
{
	fastio();
	vector<array<int,3>>vc;
	int n;
	cin>>n;
	int x[10000],y[10000];
	f(i,1,n+1)
	cin>>x[i]>>y[i];
	f(i,1,n+1)
	{
		cin>>c[i];
		vc.pb({c[i],i,0});
	}
	f(i,1,n+1)
	cin>>k[i];
	vector<int>pw;
	vector<pair<int,int>>jn;
	while(1)
	{
		if(vc.size()==0)
			break;
		sort(vc.begin(),vc.end());
		reverse(vc.begin(),vc.end());
		auto bb=vc.back();
		vc.pop_back();
		if(bb[2]==0)
		{
			pw.pb(bb[1]);
		}
		else
		{
			jn.pb(mp(bb[1],bb[2]));
		}
		ans+=bb[0];
		if(vc.size()==0)
			break;
		int i1=bb[1];
		for(int i=0;i<vc.size();i++)
		{
			auto cc=vc[i];
			int i2=cc[1];
			int cs=(k[i1]+k[i2])*(abs(x[i1]-x[i2])+abs(y[i1]-y[i2]));
			if(cs<cc[0])
			{
				vc[i]={cs,cc[1],i1};
			}
		}
	}
	cout<<ans<<endl;
	cout<<pw.size()<<endl;
	f(i,0,pw.size())
	cout<<pw[i]<<" ";
	cout<<endl;
	cout<<jn.size()<<endl;
	f(i,0,jn.size())
	cout<<jn[i].first<<" "<<jn[i].second<<endl;
}