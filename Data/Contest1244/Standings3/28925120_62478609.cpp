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
const int maxn = 1020;
const int mod = 998244353;
LL exgcd(LL a, LL b, LL &x, LL &y);

int main()
{
	LL n, p, w, d, dx, x, y, z;
	scanf("%I64d %I64d %I64d %I64d", &n, &p, &w, &d);
	dx = exgcd(d, w, y, x);
	if(p % dx)
		printf("-1\n");
	else{
		LL md = w/dx;
		y *= (p/dx)%md;
		y = (y%md+md)%md;
		x = (p-d*y)/w;
		z = n-x-y;
		if(x<0 || y<0 || z<0)
			printf("-1");
		else
			printf("%I64d %I64d %I64d\n", x, y, z);
	}
	return 0;
}

LL exgcd(LL a, LL b, LL &x, LL &y)
{
	if(!b){
		x = 1, y =0;
		return a;
	}
	LL d = exgcd(b, a%b, y, x);
	y -= a/b*x;
	return d;
}
