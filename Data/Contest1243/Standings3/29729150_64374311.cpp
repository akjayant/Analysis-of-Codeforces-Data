#include<bits/stdc++.h>
using namespace std;
namespace RNG{
    unsigned int seed;
    void init(int p){seed=p;}
    unsigned int rnd()
    {
        unsigned int res=(seed<<4)+(seed^0x23414326)-(seed>>4)-(seed^0x54378320);
        return (seed=((seed+res<<1)^res)>>1);
    }
}
int n,lis[1005];
void solve()
{
	cin>>n;for(int i=1;i<=n;lis[i]=-lis[i],++i)cin>>lis[i];
	sort(lis+1,lis+1+n);
	for(int i=1;i<=n;++i)lis[i]=-lis[i];
	int ans=0,mi=10000;
	for(int i=1;i<=n;++i)
	{
		mi=min(mi,lis[i]);
		ans=max(ans,min(mi,i));
	}
	cout<<ans<<endl;
}
int main()
{
	int t;cin>>t;while(t--)solve();
}