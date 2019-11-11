#include<bits/stdc++.h>
typedef long long ll;
ll mod =1000000007;
using namespace std;
int n;

ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int main()
{
	int i,j,fl,test,r,p,s;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d",&n);
		string al;
		
		char ans[200];
		for(i=0;i<n;i++)
		{
			ans[i]='0';
		}
		scanf("%d%d%d",&r,&p,&s);
		cin>>al;
		int wins=0;
		for(i=0;i<n;i++)
		{
			if(al[i]=='R')
			{
				if(p)
				{
					p--;
					wins++;
					ans[i]='P';
				}
			}
			else if(al[i]=='P')
			{
				if(s)
				{
					s--;
					wins++;
					ans[i]='S';
				}
			}
			else
			{
				if(r)
				{
					r--;
					wins++;
					ans[i]='R';
				}
			}
		}
		if(wins>=(n+1)/2)
		{
			printf("YES\n");
			for(i=0;i<n;i++)
			{
				if(ans[i]=='0')
				{
					if(s)
					{
						s--;
						printf("S");
					}
					else
					if(r)
					{
						r--;
						printf("R");
					}
					else
					if(p)
					{
						p--;
						printf("P");
					}
				}
				else
					printf("%c",ans[i] );
			}

		
		}
		else
			printf("NO");
		printf("\n");
	}
	return 0;
}