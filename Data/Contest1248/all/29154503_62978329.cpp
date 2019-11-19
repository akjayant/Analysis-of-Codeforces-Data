#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
using namespace std;
#define MAXN 500000
#define MOD 998244353
#define DB double
#define LL long long
#define Pr pair<int,int>
#define X first
#define Y second
LL read(){
   	LL x=0,F=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')F=-1;c=getchar();}
   	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*F;
}
int n,m,p[MAXN+5],q[MAXN+5];
int cnt1,cnt2;
int T;LL ans;
int main()
{
	T=read();
	while(T--){
		cnt1=0,cnt2=0;ans=0;
		n=read();
		for(int i=1;i<=n;i++){
			p[i]=read();
			if(p[i]%2==0)cnt1++;
			else cnt2++;
		}
		m=read();
		for(int i=1;i<=m;i++){
			q[i]=read();
			if(q[i]%2==0)ans+=cnt1;
			else ans+=cnt2;
		}
		printf("%lld\n",ans);
	}
}