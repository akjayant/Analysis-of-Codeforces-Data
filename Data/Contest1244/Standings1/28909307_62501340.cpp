#include<bits/stdc++.h>
#define MAX_N 200005
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
int n,k;
char in_s[MAX_N];
int V[MAX_N];
int main(){
	int i;
	scanf("%d %d",&n,&k);
	scanf("%s",in_s);
	for(i=0;i<n;i++){
		V[i] = (in_s[i] == 'B') ? 1 : 0;
	}
	int Z = 0;
	for(i=0;i<n;i++){
		if(V[(i+n-1)%n]%2 == V[i]%2 || V[i]%2 == V[(i+1)%n]%2){V[i] = V[i]+2;Z++;}
	}
	if(!Z){
		for(i=0;i<n;i++){
			printf("%c",(V[i] + k)%2?'B':'W');
		}
		printf("\n");
		return 0;
	}
	if(Z == n)	return !printf("%s\n",in_s);
	for(i=0;i<n;i++){
		if(V[i]>1)	break;
	}
	Z=i;
	while(1){
		if(V[i]>1){
			i = (i+1)%n;
			if(i == Z)	break;
			continue;
		}
		int s = i, e = i;
		while(V[(e+1)%n]<2)	e = (e+1)%n;
		int v;
		if(s>e){
			v = (e-s+1+n)/2 + (e-s+1+n)%2;
		}else{
			v = (e-s+1)/2 + (e-s+1)%2;
		}
		int j = min(v,k);
		int c = V[(s-1+n)%n];
		int y = s;
		while(j--){
			V[y] = c;
			y = (y+1) % n;
		}
		y = e;
		c = V[(e+1)%n];
		j = min(v,k);
		while(j--){
			V[y] = c;
			y = (y-1+n) % n;
		}
		i = (e+1) %n;
		if(Z == i)	break;
	}
	for(i=0;i<n;i++){
		if(V[i]>1)	printf("%c",(V[i]%2)?'B':'W');
		else	printf("%c",((V[i]+k)%2)?'B':'W');
	}
	printf("\n");
	return 0;
}