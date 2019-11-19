#include <cstdio>
#include <algorithm>
using namespace std;

int n,pk[2];
char pi[2333];

int huan(int x,int y)
{
	char a=pi[x]; pi[x]=pi[y]; pi[y]=a;
	int ss=0,p=0,s=0;
	for(int i=0; i<n; i++) if(pi[i]=='(') p++;
	else
	{
		p--; if(p==s) ss++;
		else if(p<s)
		{
			s=p; ss=1;
		}
	}
	a=pi[x]; pi[x]=pi[y]; pi[y]=a;
	return ss;
}

int main()
{
	int p=0,sum; scanf("%d",&n);
	scanf("%s",pi);
	for(int i=0; i<n; i++) if(pi[i]=='(') p++;
	else p--;
	if(p!=0)
	{
		printf("0\n1 1"); return 0;
	}
	sum=huan(0,0); pk[0]=0; pk[1]=0;
	for(int i=0; i<n; i++) for(int j=i+1; j<n; j++) if(pi[i]!=pi[j])
	{
		int ss=huan(i,j); if(ss>sum)
		{
			sum=ss; pk[0]=i; pk[1]=j;
		}
	}
	printf("%d\n%d %d",sum,pk[0]+1,pk[1]+1);
	return 0;
}
