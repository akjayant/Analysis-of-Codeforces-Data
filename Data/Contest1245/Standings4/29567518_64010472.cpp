#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int x,y,n,r1,p1,s1,r2,p2,s2,t;
char s[200];
int f[200];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		scanf("%d%d%d",&r1,&p1,&s1);
		getchar();
		gets(s);
		r2=p2=s2=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='R') r2++;
			if (s[i]=='P') p2++;
			if (s[i]=='S') s2++;
		}
		int m;
		if (n%2==0) m=n/2; else m=n/2+1;
		if (min(p1,r2)+min(s1,p2)+min(r1,s2)>=m) printf("YES\n");
		else 
		{
			printf("NO\n");
			continue;
		}
		for (int i=0;i<n;i++) 
		{
			if (s[i]=='R'&&p1) f[i]=1,p1--;
			if (s[i]=='P'&&s1) f[i]=2,s1--;
			if (s[i]=='S'&&r1) f[i]=3,r1--;
		}
		for (int i=0;i<n;i++) if (!f[i])
		{
			if (p1) p1--,f[i]=1; else if (s1) s1--,f[i]=2;
			else if (r1) r1--,f[i]=3;
		}
		for (int i=0;i<n;i++)
		{
			if (f[i]==1) printf("P"); 
			if (f[i]==2) printf("S");
			if (f[i]==3) printf("R");
		}
		printf("\n");
	} 
} 