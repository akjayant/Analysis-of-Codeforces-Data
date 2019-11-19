#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
#define sqr(x) ((x)*(x))
#define pb push_back
const int N=1000002,M=998244353;
int pw(int x,int y){int z=1;for(;y;y>>=1,x=1ll*x*x%M)if(y&1)z=1ll*z*x%M;return z;}
void inc(int &x,int y){x+=y;if(x>=M)x-=M;}void dec(int &x,int y){x-=y;if(x<0)x+=M;}
void Max(int &x,int y){if(y>x)x=y;}void Min(int &x,int y){if(y<x)x=y;}
//struct node{int to,ne;}e[];
//void add(int x,int y){e[++tot]=(node){y,h[x]},h[x]=tot;}
int T,n,i,mx,mn;
char s[N];
signed main(){
	scanf("%d",&T);
	for (;T--;){
		scanf("%d%s",&n,s+1);
		mn=n+1,mx=0;
		for (i=1;i<=n;i++)
			if (s[i]=='1') mx=max(mx,i),mn=min(mn,i);
		if (mn==n+1) printf("%d\n",n);
		else printf("%d\n",max(mx,n-mn+1)*2);
	}
}