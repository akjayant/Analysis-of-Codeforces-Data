#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
inline int read(){
	register int res=0, c;
	while(c=getchar(), c<'0'||c>'9');
	do{
		res=(res*10)+(c^48);
	} while(c=getchar(), c>='0'&&c<='9');
	return res;
}
#define LL long long
LL e_gcd(LL a, LL b, LL &x, LL &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	LL ans=e_gcd(b, a%b, x, y);
	LL temp=x;
	x=y;
	y=temp-a/b*y;
	return ans;
}

LL cal(LL a, LL b, LL c)
{
	LL x, y;
	LL gcd=e_gcd(a, b, x, y);
	if(c%gcd) return -1;
	b/=gcd;//约去c后原来b就变为了b/gcd;
	x*=(c/gcd%b);//转化为a*x+b*y=c的解
	LL ans = (x%b+b)%b;
	return ans;//返回的就是最小正整数解
}

int main() {
	long long n, c, a, b;
	scanf("%lld%lld%lld%lld", &n, &c, &a, &b);
	bool swaped = a>b;
	if(a>b)swap(a, b);
	LL x = cal(a, b, c);
	LL y = (c-x*a)/b;
	if(x==-1 || y<0 || x+y>n)puts("-1");
	//if(x*a+y*b!=c)while(1);
	else{
		if(swaped)swap(x, y);
		printf("%lld %lld %lld\n", x, y, n-x-y);
	}

	return 0;
}

/*
1000000000000 77777777 100000 99999
*/