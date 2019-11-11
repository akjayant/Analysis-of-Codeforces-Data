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

const int N = 2010;
const int mod = 1 << 30;
const int msk = mod - 1;

int a,b,c,n;
char s[N],st[N];

int main()
{
    int T;
    sc(T);
    while(T--)
    {
    	int n; sc(n);
    	sccc(a,b,c);
    	scanf("%s",s);
    	int t=0;
    	memset(st,0,sizeof(st));
    	for(int i=0;i<n;i++)
    	{
    		if (s[i]=='R'&&b) b--,t++,st[i]='P';
    		if (s[i]=='P'&&c) c--,t++,st[i]='S';
    		if (s[i]=='S'&&a) a--,t++,st[i]='R';
    	}
    	for(int i=0;i<n;i++)
    	{
    		if (st[i]!=0) continue;
    		if (a) a--,st[i]='R';
    		else if (b) b--,st[i]='P';
    		else if (c) c--,st[i]='S';
    	}
    	if (t*2>=n)
    	{
    		puts("YES");
    		printf("%s\n",st);
    	} else puts("NO");
    }
    return 0;
}
