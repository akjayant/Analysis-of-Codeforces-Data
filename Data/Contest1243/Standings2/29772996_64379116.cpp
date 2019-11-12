#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define debug printf("\n-------------\n")
using namespace std;
typedef long long ll;
int n,a[1010],mx;
void solve()
{
	scanf("%d",&n);
	mx=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n;i++)
		mx=max(mx,min(i,a[i]));
	printf("%d\n",mx);
}
int main()
{
	int K;
	scanf("%d",&K);
	while(K--)
		solve();
	return 0;
}