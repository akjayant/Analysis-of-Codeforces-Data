#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int  n,m;
		scanf("%d",&n);
		ll ji1,ou1,ji2,ou2;
		ji1=ou1=ji2=ou2=0;
		ll p,q;
		for(int i=1;i<=n;i++)
		{
			cin>>p;
			if(p%2)ji1++;
			else ou1++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			cin>>q;
			if(q%2) ji2++;
			else ou2++;
		}
		ll ans=(ji1*ji2)+(ou1*ou2);
		cout<<ans<<endl;
	}
	return 0;
 } 