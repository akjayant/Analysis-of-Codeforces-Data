#include<bits/stdc++.h>
#define LL long long
using namespace std;

int a[100005];
LL sum[100005];
int main()
{
    int n;
    LL k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
		
	int H=1,T=1;
	LL ans=1e9+1;
	while(true)
	{
		ans=a[n-T+1]-a[H];
		if(H==n-T+1) break;
		if(H<=T)
		{
			LL p=min(k/H,(LL)a[H+1]-(LL)a[H]);
			if(p!=(LL)a[H+1]-a[H])
			{
				ans-=p;
				break;
			}
			k-=(LL)H*p;H++;
		}
		else
		{
			LL p=min(k/T,(LL)a[n-T+1]-(LL)a[n-T]);
			if(p!=(LL)a[n-T+1]-(LL)a[n-T])
			{
				ans-=p;
				break;
			}
			k-=(LL)T*p;T++;
		}
		ans=a[n-T+1]-a[H];
	//	cout<<"H: "<<H<<" T:"<<T<<" K:"<<k<<" ans:"<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
