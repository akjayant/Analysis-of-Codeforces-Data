#include<bits/stdc++.h>
#include<math.h>
#define rep(i,k,n) for(int i=k;i<n;i++)
#define ll long long
#define MOD 1000000007LL
#define ROD 100000000ll
#define INF 123456789123456ll
#define MIN(a,b) (a>b?b:a)
using namespace std;
#define mp make_pair
#define  piii pair<pair<ll,ll>,pair<ll,ll>>
#define pii pair<ll,ll>
#define fi first
#define se second
map <ll,ll> m;
ll n,k,x;
pii p1,p2,p3;
int main()
{
	scanf("%lld %lld",&n,&k);
	rep(i,0,n)
	{
		scanf("%lld",&x);
		m[x]++;
	}
	while(k)
	{
		p1=*m.begin(),p2=*m.rbegin();
		//cout<<p1.fi<<" "<<p1.se<<" "<<p2.fi<<" "<<p2.se<<" "<<k<<"\n";		
		if(p1.fi==p2.fi)
		break;
		if(p1.se<p2.se)
		{
			m.erase((*m.begin()).fi);
			p3=*m.begin();
			if(p1.se*(p3.fi-p1.fi)<=k)
			{
				k-=p1.se*(p3.fi-p1.fi);
				m[p3.fi]+=p1.se;
			}
			else
			{
				m.insert(mp(p1.fi+k/p1.se,p1.se));
				break;
			}
		}
		else
		{
			m.erase((*m.rbegin()).fi);
			p3=*m.rbegin();
			//cout<<p3.fi<<" "<<p3.se<<"\n";
			if(p2.se*(p2.fi-p3.fi)<=k)
			{
				k-=p2.se*(p2.fi-p3.fi);
				m[p3.fi]+=p2.se;
				//cout<<"SF"<<p2.fi<<" ";
			}	
			else
			{
				//cout<<k<<" "<<p3.fi<<" "<<p3.fi-k/p2.se<<"GHJ\n";
				m.insert(mp(p2.fi-k/p2.se,p2.se));
				break;
			}
			//cout<<p3.fi<<" "<<p3.se<<"\n";
		}
		//cout<<m[2]<<"\n";
	}
	p1=*m.begin();
	p2=*m.rbegin();
	//cout<<p1.fi<<" "<<p1.se<<" "<<p2.fi<<" "<<p2.se<<" "<<k<<"\n";
	printf("%lld",p2.fi-p1.fi);
}