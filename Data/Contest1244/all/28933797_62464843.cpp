#include<bits/stdc++.h>
using namespace std;
inline int read ()
{
	int s=0,w=1;
	char ch=getchar ();
	while (ch<'0'||ch>'9'){if (ch=='-') w=-1;ch=getchar ();}
	while ('0'<=ch&&ch<='9') s=(s<<1)+(s<<3)+(ch^48),ch=getchar ();
	return s*w;
}
int t,a,b,c,d,k;
int main()
{
	t=read ();
	while (t--)
	{
		a=read (),b=read (),c=read (),d=read (),k=read ();
		bool flag=0;
		for (int i=0;i<=k;i++)
		{
			int x=i,y=k-i;
			if (x*c>=a&&y*d>=b)
			{
				flag=1;
				printf ("%d %d\n",x,y);
				break;
			}
		}
		if (!flag) printf ("-1\n"); 
	}
	return 0;
}
