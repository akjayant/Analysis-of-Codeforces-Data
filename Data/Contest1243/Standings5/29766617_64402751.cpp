#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
#define ll long long
#define cin(x) scanf("%d",&x)
#define cout(x) printf("%d\n",x)
#define rep(i,k,n) for(ll i=k;i<=n;i++)
#define mst(a,k) memset(a,k,sizeof(a));
const ll INF = 1e12 + 5;
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
ll T,n,a[maxn],num1[50],num2[50],flag,ans[maxn][2],z;
char s[maxn],t[maxn];
int main(){
	scanf("%lld",&T);
	while(T--){
		flag=0;z=0;
		mst(num1,0);
		mst(num2,0);
		scanf("%lld",&n);
		scanf("%s%s",&s,&t);
		rep(i,0,n-1){
			num1[s[i]-'a']++;
			num2[t[i]-'a']++;
		}
		rep(i,0,25) if((num1[i]+num2[i])%2!=0){
			printf("No\n");
			flag=1;
			break;
		}
		if(!flag){
			rep(i,0,n-1){
				char nw=s[i];
				if(s[i]==t[i]) continue;
				rep(j,i+1,n-1){
					if(s[j]==nw&&s[j]!=t[j]){
						ans[++z][0]=j;
						ans[z][1]=i;
						swap(s[j],t[i]);
						break;
					}
				}
				if(s[i]!=t[i]){
					rep(j,i+1,n-1){
						if(t[j]==nw&&s[j]!=t[j]){
							ans[++z][0]=j;
							ans[z][1]=j;
							ans[++z][0]=j;
							ans[z][1]=i;
							swap(s[j],t[j]);
							swap(s[j],t[i]);
							break;
						}
					}
				}
			}
			if(z>2*n) flag=1;
			rep(i,0,n-1) if(s[i]!=t[i]) flag=1;
			if(!flag){
				printf("Yes\n%lld\n",z);
				rep(i,1,z) printf("%lld %lld\n",ans[i][0]+1,ans[i][1]+1);
			}
			else printf("No\n");
		}
	}
	return 0;
}