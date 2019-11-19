#include <cstdio>
#include <algorithm>
using namespace std;
long long num[100010];
int main()
{
	long long n,tmp; scanf("%lld",&n),tmp=n;
	for(int i=2;1ll*i*i<=tmp;i++) if(tmp%i==0)
		{num[++num[0]]=i;while(tmp%i==0) tmp/=i;}
	if(tmp!=1) num[++num[0]]=tmp;
	if(num[0]==1) printf("%lld\n",num[1]);
	else printf("%d\n",1);
}