#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rint register int
using namespace std;
const int N=510;
int n,ans,ort1,ort2;
char a[N];
inline int f()
{
	int sum=0;
	for(rint i=1;i<=n;++i)
	{
		if(a[i]==')')
			--sum;
		else
			++sum;
	}
	if(sum!=0)
		return 0;
	for(rint i=1;i<=n;++i)
		a[i+n]=a[i];
	for(rint i=1;i<=n;++i)
	{
		int flag=0;
		sum=0;
		for(rint j=i;j<i+n;++j)
		{
			if(a[j]==')')
				--sum;
			else
				++sum;
			if(sum<0)
			{
				while(a[j]==')')
					++j;
				i=j;
				flag=1;
				break;
			}
		}
		flag=0;
		int tot=0;
		sum=0;
		for(rint j=i;j<i+n;++j)
		{
			if(a[j]==')')
				--sum;
			else
				++sum;
			if(!sum)
				++tot;
			if(sum<0)
			{
				flag=1;
				break;
			}
		}
		if(!flag)
			return tot;
	}
	return 0;
}
int main()
{
	scanf("%d%s",&n,a+1);
	for(rint i=1;i<=n;++i)
		for(rint j=i+1;j<=n;++j)
		{
			swap(a[i],a[j]);
			int x=f();
			if(x>ans)
			{
				ans=x;
				ort1=i,ort2=j;
			}
			swap(a[i],a[j]);
		}
	if(!ans)
		printf("0\n1 1");
	else
		printf("%d\n%d %d",ans,ort1,ort2);
	return 0;
}
