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
#define int long long
int ggcd(int a,int b){return b?ggcd(b,a%b):a;}
signed main()
{
	int n;
	cin>>n;
	int ans=n;
	for(int i=2;i*i<=n;++i)
	{
		if(!(n%i))
		{
			ans=ggcd(ans,i);
			ans=ggcd(ans,n/i);
		}
	}
	cout<<ans<<endl;
	return 0;
}
