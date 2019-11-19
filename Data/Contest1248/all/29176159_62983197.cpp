#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define dwn(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while('0'>ch || ch>'9'){if(ch=='-') f=-1; ch=getchar();}
	while('0'<=ch && ch<='9'){x=(x<<1)+(x<<3)+ch-'0'; ch=getchar();}
	return x*f;
}
int n,a[1000050],s1,s2;
signed main(){
    n=read();
    rep(i,1,n) a[i]=read();
    sort(a+1,a+n+1);
    rep(i,1,n/2) s1+=a[i];
    rep(i,(n/2)+1,n) s2+=a[i];
    printf("%lld",s2*s2+s1*s1);
	return 0;
}