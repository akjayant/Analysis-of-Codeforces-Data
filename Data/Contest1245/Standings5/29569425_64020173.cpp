#include<bits/stdc++.h>
using namespace std;
#define maxn 100050
#define ll long long
#define cin(x) scanf("%d",&x)
#define cout(x) printf("%d\n",x)
#define rep(i,k,n) for(ll i=k;i<=n;i++)
#define mst(a,k) memset(a,k,sizeof(a));
const ll INF = 1e12 + 5;
const ll mod = 1e9 + 7;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*f;
}
inline void write(int x){
	char c[20];int l=0;
	while(x) c[++l]=x%10+48,x/=10;
	while(l) putchar(c[l--]);
	putchar('\n');
}
ll n,len,f[maxn],now,flag,ans=1;
char s[maxn];
int main(){
	scanf("%s",&s);
	mst(f,0);
	len=strlen(s);
	f[0]=1,f[1]=1;
	rep(i,2,len) f[i]=(f[i-1]+f[i-2]) % mod;
	rep(i,0,len-1){
		if(s[i]=='m'||s[i]=='w'){
			flag=1;break;
		}  
	}
	if(flag) printf("0");
	else{
		ll i=0;
		while(i<=(len-1)){
			if(s[i]=='u'||s[i]=='n'){
				now=1;
				while(s[i+1]==s[i]) i++,now++;
				ans=(ans*f[now])%mod;
			}
			i++;
		}
		printf("%lld",ans%mod);
	} 
	return 0;
}
