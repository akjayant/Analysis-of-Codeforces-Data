//problem:
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define lob lower_bound
#define upb upper_bound
#define fst first
#define scd second

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read(){
	int f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
inline ll readll(){
	ll f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int MOD=1e9+7;
int n,m;
inline int pow_mod(int x,int i){
	int y=1;
	while(i){
		if(i&1)y=(ll)y*x%MOD;
		x=(ll)x*x%MOD;
		i>>=1;
	}
	return y;
}
int main() {
	n=read();m=read();
	cout<<pow_mod(pow_mod(2,m)-1,n)<<endl;
	return 0;
}
