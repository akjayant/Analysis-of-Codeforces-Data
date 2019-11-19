#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long lint;
lint a[100011];
lint ans;int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n/2;i++) ans+=a[i];
	lint p=0;
	for(int i=n;i>n/2;i--) p+=a[i];
	ans=ans*ans+p*p;
	printf("%I64d\n",ans);
	return 0;
}