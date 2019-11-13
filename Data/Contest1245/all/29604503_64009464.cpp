#include <bits/stdc++.h>
using namespace std;
bool ds[110];
int main()
{
	int T; scanf("%d",&T);
	while(T--)
	{
		memset(ds,0,sizeof(ds));
		int n,a,b,c; scanf("%d",&n);
		scanf("%d %d %d",&a,&b,&c);
		string k; cin>>k;
		int ans=0; string g;
		for(register int i=0;i<n;i++)
		{
			if(k[i]=='R'&&b) 
			{
				b--; ds[i]=1;
			}
			else if(k[i]=='S'&&a)
			{
				a--; ds[i]=1;
			}
			else if(k[i]=='P'&&c)
			{
				c--; ds[i]=1;
			}
			if(ds[i]) ans++;
		}
		if(ans>=(n+1)/2)
		{
			cout<<"YES"<<endl;
			for(register int i=0;i<n;i++)
			{
				if(ds[i]) 
				{
					if(k[i]=='R') cout<<'P';
					else if(k[i]=='S') cout<<'R';
					else if(k[i]=='P') cout<<'S';
				}
				else 
				{
					if(a) cout<<'R',a--;
					else if(b) cout<<'P',b--;
					else if(c) cout<<'S',c--;
				}
			}
			cout<<endl;
		}
		else cout<<"NO"<<endl;
	}
}