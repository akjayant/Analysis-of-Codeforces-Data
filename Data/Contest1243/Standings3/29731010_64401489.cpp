#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define pb push_back
#define INF 0x3f3f3f3f
#define sc(x) scanf("%d",&x)
#define scc(x,y) scanf("%d%d",&x,&y)
#define sccc(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;

const int N=110;

char s[N],t[N];
int mp[N],pos[N][2],position[N],cnt[26];
bool up[N],v[N];

inline void Swap1(int x,int y)
{
	int a=pos[x][0],b=pos[y][1];
	swap(pos[x][0],pos[y][1]);
	up[a]=1; up[b]=0;
	position[a]=y;
	position[b]=x;
}

int main()
{
	int T;
	sc(T);
	while(T--)
	{
		int n; sc(n);
		scanf("%s",s);
		scanf("%s",t);
		memset(v,0,sizeof(v));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<n;i++)
			cnt[s[i]-'a']++,cnt[t[i]-'a']++;
		bool flag=1;
		for(int i=0;i<26;i++)
			if (cnt[i]&1) {flag=0;break;}
		if (!flag) {puts("No");continue;}
       	puts("Yes");
       	for(int i=0;i<n;i++)
       	{
       		pos[i][0]=i;
       		pos[i][1]=i+n;
       		position[i]=position[i+n]=i;
       		up[i]=0; up[i+n]=1;
       	}
       	for(int i=0;i<n;i++)
       	{
       		if (v[i]) continue;
       		bool fg=0;
       		for(int j=i+1;j<n;j++)
       			if (!v[j]&&s[i]==s[j]) {mp[i]=j,mp[j]=i,v[j]=v[i]=fg=1;break;}
       		if (!fg)
       			for(int j=0;j<n;j++)
       				if (!v[j+n]&&s[i]==t[j]) {mp[i]=j+n,mp[j+n]=i,v[j+n]=v[i]=1;break;}
       	}
       	for(int i=0;i<n;i++)
       	{
       		if (v[i+n]) continue;
       		for(int j=i+1;j<n;j++)
       			if (!v[j+n]&&t[i]==t[j]) {mp[i+n]=j+n,mp[j+n]=i+n,v[j+n]=v[i+n]=1;break;}
       	}
       	std::vector<pair<int,int> > ans;
		for(int i=0;i<n;i++)
		{
			int now=pos[i][0];
			int tar=mp[now];
			if (position[tar]==i) continue;
			if (up[tar])
			{
				ans.pb({n-1,position[tar]});
				Swap1(n-1,position[tar]);
				ans.pb({n-1,i});
				Swap1(n-1,i);
			} else
			{
				ans.pb({position[tar],i});
				Swap1(position[tar],i);
			}
		}
		printf("%d\n", ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d %d\n",ans[i].fi+1,ans[i].se+1);
	}
	return 0;
}
