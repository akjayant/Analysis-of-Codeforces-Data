#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+999;
int n,m,t;
int cnt1,cnt2,p[maxn],q[maxn];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt1=cnt2=0;
		for(int i=1;i<=n;++i)scanf("%d",&p[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;++i)scanf("%d",&q[i]);
		for(int i=1;i<=n;++i)
			if(p[i]&1)cnt1++;
			else cnt2++;
		long long ans=0;
		for(int i=1;i<=m;++i){
			if(q[i]&1)ans+=cnt1;
			else ans+=cnt2;
		}
		cout<<ans<<endl;
	}
}