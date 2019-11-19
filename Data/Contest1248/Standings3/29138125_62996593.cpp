#include<cstdio>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
long long num[maxn];
int main(){
	num[0] = num[1] = 2;
	for(int i = 2; i <= 100000; i++)
		num[i] = (num[i - 1] + num[i - 2]) % mod;
	int n,m;
	scanf("%d%d",&n,&m);
	long long ans = num[n];
	for(int i = 0; i < m - 1; i++)
		ans = (ans + num[i]) % mod;
	printf("%lld\n",ans);
	return 0;
}