#include<bits/stdc++.h>
#define MAX_N 100005
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
#define inf (1LL<<60)
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
LL n,k;
LL V[MAX_N];
int main(){
	LL i;
	scanf("%lld %lld",&n,&k);
	for(i=0;i<n;i++){
		scanf("%lld",&V[i]);
	}
	sort(V,V+n);
	LL l = 0, r = n-1;
	while(k){
		while(l-1<n && V[l] == V[l+1])	l++;
		while(r>l && V[r] == V[r-1])	r--;
		if(l>=r)	return !printf("0\n");
		if(l+1<=n-r){
			if(k<=(l+1) * (V[l+1] - V[l])){
				printf("%lld\n",V[r] - V[l] - k/(l+1));
				return 0;
			}else{
				k-=(l+1) * (V[l+1] - V[l]);
				l++;
			}
		}else{
			if(k<=(n-r) * (V[r] - V[r-1])){
				printf("%lld\n",V[r]-k/(n-r)-V[l]);
				return 0;
			}else{
				k-=(n-r) * (V[r] - V[r-1]);
				r--;
			}
		}
	}
	printf("%lld\n",V[r] - V[l]);
	return 0;
}