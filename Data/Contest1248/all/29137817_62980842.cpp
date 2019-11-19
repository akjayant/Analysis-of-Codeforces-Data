#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int N=1e5+50;
int w[N],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(w+1,w+n+1);
	LL sum=0,X=0;
	for(int i=1;i<=n/2;i++) X+=w[i];
	for(int i=1;i<=n;i++) sum+=w[i];
	printf("%lld",X*X+(sum-X)*(sum-X));
	return 0;
}