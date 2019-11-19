#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1100000;
int n,k,a[N],ans;
bool Check() {return k*2<(n+1)*n; }
void Solve1() {for(int i=1;i<=n;i++) a[i]=i,ans+=max(i,n-i+1); k=min(k,ans); printf("%I64d\n",k); }
void Solve2()
{
	k=k-(n+1)*n/2;
	for(int i=1,pro=n+1-2*i;;i++,pro=n+1-2*i)
	{
		if(pro>=k||k==0) {swap(a[i],a[i+k]); for(int j=1;j<n;j++) printf("%I64d ",a[j]); printf("%I64d\n",a[n]); return;}
		else {k-=pro; swap(a[i],a[n-i+1]); }
	}
}
signed main()
{
	scanf("%I64d %I64d",&n,&k);
	if(Check()) {printf("-1\n"); return 0; }
	Solve1(); for(int i=1;i<n;i++) printf("%I64d ",i); printf("%I64d\n",n); Solve2();
	return 0;
}