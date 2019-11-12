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

const int N=10010;

char s[N],t[N];
bool v[N];

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
		int tt=0,flag=0;
		for(int i=0;i<n;i++)
            if (s[i]!=t[i]) tt++,v[i]=1;
        if (tt>2) {puts("No");continue;}
		for(int i=0;s[i];i++)
		{
		    if (!v[i]) continue;
			for(int j=0;t[j];j++)
			{
			    if (!v[j]) continue;
				swap(s[i],t[j]);
				if (strcmp(s,t)==0) {flag=1;break;}
				swap(s[i],t[j]);
			}
			if (flag) break;
		}
		if (flag) puts("Yes"); else puts("No");
	}
	return 0;
}
