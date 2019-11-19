#include<bits/stdc++.h>
#define MAX_N 8005
#define MAX_M 55
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(V) (V).begin(),(V).end()
#define reset(V) (V).clear();(V).resize(0);
#define sq(x) ((x)*(x))
#define abs(x) ((x)>0?(x):(-(x)))
#define fi first
#define se second
#define LL_inf (1LL<<40)
#define full_inf 0x7fffffff
#define half_inf 0x3fffffff
#define inf 0x3fffffff
#define MOD 1000000007
#define cpx_mod(x) (((LD)(((LL)x.real())%MOD)),((LD)(((LL)x.imag())%MOD)))
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pil;
typedef pair<LL,string> pls;
typedef complex<LD> Complex;
typedef long double LD;
int main(){
	LL n,p,w,d;
	LL x,y,z;
	scanf("%lld %lld %lld %lld",&n,&p,&w,&d);
	x = p/w;
	if((p%w)%d == 0){
		if(n - x - (p%w)/d<0)	return !printf("-1\n");
		return !printf("%lld %lld %lld\n",x,(p%w)/d,n - x - (p%w)/d);
	}
	for(int t=0;t<1000055;t++){
		x--;
		z = w * x;
		if(x<0)	break;
		if((p-z)%d == 0){
			y = (p-z)/d;
			if(x+y > n)	return !printf("-1\n");
			return !printf("%lld %lld %lld\n",x,y,n-x-y);
		}
	}
	printf("-1\n");
	return 0;
}