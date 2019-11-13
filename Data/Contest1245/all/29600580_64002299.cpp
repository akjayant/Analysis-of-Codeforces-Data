#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;

int T,a,b,c,n,S,A,B,C,W,na,nb,nc,i;
char str[10005];

int main()
{
//	freopen("read.in","r",stdin);
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		if (n%2==0) W=n/2;
		else W=(n+1)/2;
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",str+1);
		S=0;
		A=B=C=0;
		for (i=1;i<=n;i++)
		{
			if (str[i]=='R') A++;
			if (str[i]=='P') B++;
			if (str[i]=='S') C++;
		}
		na=min(a,C);
		nb=min(b,A);
		nc=min(c,B);
		S=na+nb+nc;
		if (S>=W)
		{
			printf("YES\n");
			for (i=1;i<=n;i++)
			{
				if (str[i]=='R')
				{
					if (nb>0)
					{
						nb--;
						b--;
						printf("P");
					}
					else
					{
						if (a>na)
						{
							a--;
							printf("R");
						}
						else
						{
							c--;
							printf("S");
						}
					}
				}
				if (str[i]=='P')
				{
					if (nc>0)
					{
						nc--;
						c--;
						printf("S");
					}
					else
					{
						if (a>na)
						{
							a--;
							printf("R");
						}
						else
						{
							b--;
							printf("P");
						}
					}
				}
				if (str[i]=='S')
				{
					if (na>0)
					{
						na--;
						a--;
						printf("R");
					}
					else
					{
						if (b>nb)
						{
							b--;
							printf("P");
						}
						else
						{
							c--;
							printf("S");
						}
					}
				}
			}
			printf("\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}