#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctype.h>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<iostream>
#include<iterator>
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define INF 0x3f3f3f3f
#define eps 1e-8

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
const int maxn = 24;
const int mod = 998244353;

int main()
{
	int t, a, b, c, d, k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		int a1 = (a-1)/c+1, a2 = (b-1)/d+1;
		if(a1 + a2 > k)
			printf("-1\n");
		else
			printf("%d %d\n", a1, a2);
	}
	return 0;
}
