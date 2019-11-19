#include<bits/stdc++.h>
#define LL long long int
#define FIO ios::sync_with_stdio(false)
#define FRD freopen("input.txt","r",stdin)
#define lowbit(x) (x&-(x))
#define INF 1e18
#define ms(x) memset(x,0,sizeof x)
#define pb(x) push_back(x)
#define lson l,mid,now<<1
#define rson mid+1,r,now<<1|1
#define UNIQUE(x) unique(x.begin(),x.end())
#define SORT(x) sort(x.begin(),x.end())
#define LISAN(x) x.erase(UNIQUE(x),x.end())
#define pii pair<int,int>
#define pll pair<LL,LL>
#define N 200010
const LL MOD=1e9+7;
using namespace std;
template<class T> inline T Min(const T& a,const T& b){return a<b?a:b;}
template<class T> inline T Max(const T& a,const T& b){return a<b?b:a;}
inline void inc(int &x,int &v,int &mod){x+=v;if(x>=mod) x-=mod;}
inline void dec(int &x,int &v,int &mod){x-=v;if(x<0) x+=mod;}
inline int read(){char ch = getchar();int x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
inline LL readl(){char ch = getchar();LL x = 0, f = 1;while(ch < '0' || ch > '9') {if(ch == '-') f = -1;ch = getchar();}while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}return x * f;}
LL extend_gcd(LL a,LL b,LL& x,LL& y){
	if(!b){
		x = 1;y = 0;
		return a;
	}
	LL d = extend_gcd(b,a%b,y,x);
	y -= x*(a/b);
	return d;
}
int main(){
	#ifndef ONLINE_JUDGE
		int start_clock = clock();
		FRD;
	#endif
	FIO;
	LL n,p,w,d;
	cin>>n>>p>>w>>d;
	LL x,y;
	LL gcd = extend_gcd(w,d,x,y);
	if(p%gcd!=0){
		cout<<"-1"<<endl;
		return 0;
	}
	else{
		LL t=w/gcd;
		y=(y%t*(p/gcd%t)%t+t)%t;
		x=(p-y*d)/w;
		LL z=n-x-y;
		if(x>=0&&z>=0){
			cout<<x<<" "<<y<<" "<<z<<endl;
		}else{
			cout<<"-1"<<endl;
		}	
	}
	return 0;
}









