#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100000+10;
ll y,sum;
int A[MAXN],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]),sum+=A[i];
	sort(A+1,A+n+1);
	int m=n/2;
	for(int i=1;i<1+m;i++) y+=A[i];
	printf("%lld",(ll)y*y+(sum-y)*(sum-y));
	return 0;
}
