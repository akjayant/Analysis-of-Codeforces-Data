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
	if(c%gcd!=0) return -1;
	x*=c/gcd;//转化为a*x+b*y=c的解
	b/=gcd;//约去c后原来b就变为了b/gcd;
	LL ans = (x%b+b)%b;
	return ans;//返回的就是最小正整数解
}
int s[100010], n;
long long k, sum[100010];
bool test(int m){
	long long mi = k+1;
	//printf("m=%d\n", m);
	for(int l=1; l<=n; l++){
		int r = lower_bound(s+1, s+1+n, s[l]+m+1) - s;
	//	printf("l = %d r = %d s[l]=%d s[r]=%d\n", l, r, s[l], s[r]);
		long long now = sum[n]-sum[r-1]-1ll*(s[l]+m)*(n-r+1)+1ll*(s[l])*(l-1)-sum[l-1];
	//	printf("now = %lld\n", now);
		mi = min(mi, now);
	}
	for(int r=n; r; r--){
		int l = lower_bound(s+1, s+1+n, s[r]-m) - s - 1;
		long long now = 1ll*(s[r]-m)*l - sum[l] + sum[n]-sum[r]-1ll*(s[r])*(n-r);
		mi = min(mi, now);
	}
	return mi <= k;
}
int main() {
	n=read();
	scanf("%lld", &k);
	for(int i=1; i<=n; i++){
		s[i]=read();
	}
	sort(s+1, s+1+n);
	for(int i=1; i<=n; i++){
		sum[i]=sum[i-1]+s[i];
	}
	int L=s[n]-s[1], R=-1;
	while(L-R>1){
		int mid = L+R>>1;
		if(test(mid)){
			L=mid;
		}
		else{
			R=mid;
		}
	}
	printf("%d\n", L);
	return 0;
}

/*
1000000000000 77777777 100000 99999
*/