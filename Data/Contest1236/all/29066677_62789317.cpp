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
//twards Master
int main() {
	int t=read();while(t--){
		int a=read(),b=read(),c=read();
		int ans1=min(a,b/2)*3+min(b-min(a,b/2)*2,c/2)*3;
		int ans2=min(a,(b-min(b,c/2))/2)*3+min(b,c/2)*3;
		cout<<max(ans1,ans2)<<endl;
	}
	return 0;
}