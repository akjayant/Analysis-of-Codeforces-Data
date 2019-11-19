#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define Maxi 500000
typedef long long ll;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int a, b, c, d, k;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		int x = a / c, y = b / d;
		if (a % c) x++;
		if (b % d) y++;
		if (x + y <= k) printf("%d %d\n", x, y);
		else puts("-1");
	}
	return 0;
}