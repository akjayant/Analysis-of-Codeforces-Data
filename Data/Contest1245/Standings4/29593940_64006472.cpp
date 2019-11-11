#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n,r,p,s,i;
	string ss,ans="";
	cin>>n>>r>>p>>s>>ss;
	for(i=0;i<n;i++)
	{
		if(ss[i]=='R')
		{
			if(p>0)
			{
				ans+="P";
				p--;
			}
			else ans+="X";
		}
		if(ss[i]=='P')
		{
			if(s>0)
			{
				ans+="S";
				s--;
			}
			else ans+="X";
		}
		if(ss[i]=='S')
		{
			if(r>0)
			{
				ans+="R";
				r--;
			}
			else ans+="X";
		}
	}
	if(n-(r+s+p)<n/2+n%2)
	{
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	for(i=0;i<n;i++)
		if(ans[i]=='X')
		{
			if(p>0)ans[i]='P',p--;
			else if(r>0)ans[i]='R',r--;
			else ans[i]='S';
		}
	cout<<ans<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--)
		solve();
}
