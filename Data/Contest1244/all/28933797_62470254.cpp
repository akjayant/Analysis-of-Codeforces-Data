#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
inline int read ()
{
	int s=0,w=1;
	char ch=getchar ();
	while (ch<'0'||ch>'9'){if (ch=='-') w=-1;ch=getchar ();}
	while ('0'<=ch&&ch<='9') s=(s<<1)+(s<<3)+(ch^48),ch=getchar ();
	return s*w;
}
int t,n;
char s[MAXN];
int solve ()
{
	int ans=n;
	int i;
	for (i=n;i>=1;i--) if (s[i]=='1') break;
	if (i) ans=max (ans,i+max (i,n-i+1));
	for (i=1;i<=n;i++) if (s[i]=='1') break;
	if (i<=n) ans=max (ans,n-i+1+max (i,n-i+1));
	return ans;
}
int main()
{
	t=read ();
	while (t--)
	{
		n=read ();
		scanf ("%s",s+1);
		printf ("%d\n",solve ());
	}
	return 0;
}
