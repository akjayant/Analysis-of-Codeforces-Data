#include<bits/stdc++.h>
using namespace std;
int n,m,k,x[111111],y[111111],cx,cy,dir,ly,ry,lx,rx,cur,gg;
long long ans;
vector<int> ho1[111111],ho2[111111],v1[111111],v2[111111];
bool f;
bool go(bool f)
{
	if (dir==1)
	{
		if (ho1[cx].empty())
		{
			ans+=(ry-cy);
			if (ry==cy && f) return 0;
			cy=ry;
		}
		else
		{
			cur=lower_bound(ho1[cx].begin(),ho1[cx].end(),cy)-ho1[cx].begin();
			if (cur==(int)ho1[cx].size()) 
			{
				ans+=(ry-cy);
				if (ry==cy && f) return 0;
				cy=ry;
			} 
			else
			{
				gg=min(ry,ho1[cx][cur]-1);
				ans+=(gg-cy);
				if (gg==cy && f) return 0;
				cy=gg;
			}
		}
		dir=2;lx=cx+1;
	}
	else if (dir==2)
	{
		if (v1[cy].empty())
		{
			ans+=(rx-cx);
			if (rx==cx && f) return 0;
			cx=rx;
		}
		else
		{
			cur=lower_bound(v1[cy].begin(),v1[cy].end(),cx)-v1[cy].begin();
			if (cur==(int)v1[cy].size()) 
			{
				ans+=(rx-cx);
				if (rx==cx && f) return 0;
				cx=rx;
			} 
			else
			{
				gg=min(rx,v1[cy][cur]-1);
				ans+=(gg-cx);
				if (gg==cx && f) return 0;
				cx=gg;
			}
		}
		dir=3;ry=cy-1;
	}
	else if (dir==3)
	{
		if (ho2[cx].empty())
		{
			ans+=(cy-ly);
			if (cy==ly && f) return 0;
			cy=ly;
		}
		else
		{
			cur=lower_bound(ho2[cx].begin(),ho2[cx].end(),-cy)-ho2[cx].begin();
			if (cur==(int)ho2[cx].size())
			{
				ans+=(cy-ly);
				if (cy==ly && f) return 0;
				cy=ly;
			}
			else 
			{
				gg=max(ly,-ho2[cx][cur]+1);
				ans+=(cy-gg);
				if (cy==gg && f) return 0;
				cy=gg; 
			}
		}
		dir=4;rx=cx-1;
	}
	else
	{
		if (v2[cy].empty())
		{
			ans+=(cx-lx);
			if (cx==lx && f) return 0;
			cx=lx;
		}
		else
		{
			cur=lower_bound(v2[cy].begin(),v2[cy].end(),-cx)-v2[cy].begin();
			if (cur==(int)v2[cy].size())
			{
				ans+=(cx-lx);
				if (cx==lx && f) return 0;
				cx=lx;
			}
			else 
			{
				gg=max(lx,-v2[cy][cur]+1);
				ans+=(cx-gg);
				if (cx==gg && f) return 0;
				cx=gg; 
			}	
		}
		dir=1;ly=cy+1;
	}
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		ho1[x[i]].push_back(y[i]);
		ho2[x[i]].push_back(-y[i]);
		v1[y[i]].push_back(x[i]);
		v2[y[i]].push_back(-x[i]);
	}
	for (int i=1;i<=n;i++)
	{
		if (ho1[i].empty()) continue;
		sort(ho1[i].begin(),ho1[i].end());
		sort(ho2[i].begin(),ho2[i].end());
	}
	for (int i=1;i<=m;i++)
	{
		if (v1[i].empty()) continue;
		sort(v1[i].begin(),v1[i].end());
		sort(v2[i].begin(),v2[i].end());
	}
	cx=1;cy=1;dir=1;ly=lx=1;ry=m;rx=n;ans=1;
	while(go(f)) f=1;
	if (ans==1ll*n*m-k) printf("Yes\n");
	else printf("No\n");
	return 0;
}