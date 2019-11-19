#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<vector>
#include<unordered_map>

#define ll long long
#define mt(a) memset(a,0,sizeof(a))
#define MAXI 2000000000
#define MAXLL 1e18+9
#define PAI pair<int,int>
#define EPS 1e-12
#define ls (rt << 1)
#define rs (rt << 1 | 1)


using namespace std;	

ll a[100009],b[100009];
int main()
{
	int n, m;
	scanf("%d%d", &n,&m);
	a[0] = 1;
	a[1] = 1; a[2] = 2;
	for (int i = 3; i <= max(n, m); i++)
		a[i] = (a[i - 1] + a[i - 2]) % (int)(1e9 + 7);

	for (int i = 1; i <= max(n, m); i++)
		b[i] = (a[i-1]+b[i-1]) % (int)(1e9 + 7);
	ll ans = 0;
	ans = a[n] * 2 + b[m - 1] * 2;
	ans = ans % (int)(1e9 + 7);
	printf("%lld\n", ans);


	return 0;
}