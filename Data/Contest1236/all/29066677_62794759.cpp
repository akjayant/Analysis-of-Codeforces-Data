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

int n,a[305][305];
int main() {
	n=read();
	for(int i=1,x=1,y=1,d=1;i<=n*n;++i){
		a[x][y]=i;
		x+=d;
		if(x==n+1)d=-1,x=n,y++;
		if(x==0)d=1,x=1,y++;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
