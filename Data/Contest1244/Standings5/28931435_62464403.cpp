//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
int main()
{
	int t=read();
	while(t--)
	{
		int a=read(),b=read(),c=read(),d=read(),k=read();
		int sa=(a+c-1)/c,sb=(b+d-1)/d;
		if(sa+sb>k)	printf("-1\n");
		else	printf("%d %d\n",sa,sb); 
	}
	return 0;
}
