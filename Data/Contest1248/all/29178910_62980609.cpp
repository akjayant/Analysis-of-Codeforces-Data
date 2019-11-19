#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t;
int n,m;



 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int a = 0,b =0;
		int tmp;
		for(int i  =1;i<=n;i++)
		{
			scanf("%d",&tmp);
			if(tmp&1)
				a++;
			else
				b++;
		}
		scanf("%d",&m);
		int c = 0,d =0;
		for(int i  =1;i<=m;i++)
		{
			scanf("%d",&tmp);
			if(tmp&1)
				c++;
			else
				d++;
		}
		long long res = 1ll*a*c+1ll*b*d;
		cout<<res<<endl;
		
		
		
	}







	return 0;
}
