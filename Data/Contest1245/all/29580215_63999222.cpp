#include <bits/stdc++.h>
using namespace std;
#define inta long long
#define ii pair<int,int>
#define mp make_pair
#define pb push_back

int main()
{
	ios_base::sync_with_stdio(0);
	int q;
	cin>>q;
	while(q--)
	{
		
		int n,a,b,c;
		cin>>n>>a>>b>>c;
		string s;
		cin>>s;
		string s2=s;
		int co=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='R')
			{
				if(b>0) b--,s2[i]='P',co++;
				else s2[i]='-';
			}
			if(s[i]=='P')
			{
				if(c>0) c--,s2[i]='S',co++;
				else s2[i]='-';
			}
			if(s[i]=='S')
			{
				if(a>0) a--,s2[i]='R',co++;
				else s2[i]='-';
			}
		}
		if(co>=(n+1)/2)
		{
			cout<<"YES\n";
			for(int i=0;i<n;i++)
			{
				if(s2[i]=='-')
				{
					if(b>0) s2[i]='P',b--;
					else if(a>0) s2[i]='R',a--;
					else if(c>0) s2[i]='S',c--;
				}
			}
			cout<<s2<<endl;
		}
		else cout<<"NO\n";
	}
	
}