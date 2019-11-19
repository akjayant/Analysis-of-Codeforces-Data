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
	int a,b,c,d,k,T;
	scanf("%d",&T);

	while(T--){
		scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
		int x = a/c + (a%c ? 1 : 0);
		int y = b/d + (b%d ? 1 : 0);
		if(x+y>k)	printf("-1\n");
		else	printf("%d %d\n",x,y);
	}
	return 0;
}