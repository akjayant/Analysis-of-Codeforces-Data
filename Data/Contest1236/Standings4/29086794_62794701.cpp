//%std
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		fh=-1,jp=getchar();
	while (jp>='0'&&jp<='9')
		out=out*10+jp-'0',jp=getchar();
	return out*fh;
}
int n,sum[329];
bool cmp(int x,int y)
{
	return sum[x]>sum[y];
}
int p[329];
vector<int> ans[329];
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
		p[i]=i;
	for(int i=1;i<=n;++i)
	{
		sort(p+1,p+1+n,cmp);
		for(int j=1;j<=n;++j)
		{
			ans[p[j]].push_back(j+(i-1)*n);
			sum[p[j]]+=j;
		}
	}
	for(int i=1;i<=n;++i,puts(""))
		for(auto x:ans[i])
			printf("%d ",x);
	return 0;
}
