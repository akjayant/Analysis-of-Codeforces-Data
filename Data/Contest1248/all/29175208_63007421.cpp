#include <iostream>
using namespace std;
const int SIZE = 1e6 + 2;
int n,m,num,cnt,dfu,siz,to[SIZE],ne[SIZE],first[SIZE],dfn[SIZE],low[SIZE],bel[SIZE],s[SIZE],deg[SIZE];
bool ins[SIZE],fail[SIZE];
void addE(int a,int b)
{
	to[++num] = b;
	ne[num] = first[a];
	first[a] = num;
}
void tarjan(int x)
{
	ins[s[++siz] = x] = true;
	low[x] = dfn[x] = ++dfu;
	for(int i = first[x];i;i = ne[i])
		if(!dfn[to[i]])
		{
			tarjan(to[i]);
			low[x] = min(low[to[i]],low[x]);
		}
		else if(ins[to[i]])
			low[x] = min(low[x],dfn[to[i]]);
	if(dfn[x] == low[x])
	{
		++cnt;
		while(true)
		{
			bel[s[siz]] = cnt;
			ins[s[siz]] = false;
			if(s[siz--] == x)
				break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	int t;
	for(cin >> t;t--;)
	{
		cin >> n >> m;
		for(int u,v,i = 1;i <= m && cin >> u >> v;addE(u,v),i++);
		for(int i = 1;i <= n;i++)
			if(!dfn[i])
				tarjan(i);
		for(int i = 1;i <= n;i++)
			for(int j = first[i];j;j = ne[j])
				deg[bel[i]] += bel[to[j]] != bel[i];
		if(cnt > 1)
		for(int i = 1;i <= cnt;i++)
			if(deg[i] == 0)
			{
				int ccnt = 0;
				for(int j = 1;j <= n;j++)
					if(bel[j] == i)
						ccnt++;
				cout << "Yes\n";
				cout << ccnt << " " << n - ccnt << endl;
				for(int j = 1;j <= n;j++)
					if(bel[j] == i)
						cout << j << " ";
				cout << endl;
				for(int j = 1;j <= n;j++)
					if(bel[j] != i)
						cout << j << " ";
				cout << endl;
				dfn[1] = 998244353;
				break;
			}
		if(dfn[1] <= n)
			cout << "No" << endl;
		for(int i = 1;i <= n;i++)
			dfn[i] = low[i] = first[i] = bel[i] = s[i] = 0;
		num = siz = dfu = cnt = 0;
	}
	return 0;
}