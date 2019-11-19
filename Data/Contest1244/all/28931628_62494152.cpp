#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
LL read(){
	LL f=0,x=0;char c=getchar();
	while(c<'0'||'9'<c){if(c=='-')f=1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
#define MAXN 100000
#define INF 0x3f3f3f3f
int a[MAXN+5],b[MAXN+5],cnt[MAXN+5];
int main(){
	int n=read();
	LL k=read();
	for(int i=1;i<=n;i++)
		b[i]=a[i]=read();
	sort(a+1,a+n+1);
	int m=unique(a+1,a+n+1)-(a+1);
	for(int i=1;i<=n;i++)
		cnt[lower_bound(a+1,a+m+1,b[i])-a]++;
	n=m;
	int L=1,R=n;
	while(L<R&&k){
		if(cnt[L]<cnt[R]){
			LL d=a[L+1]-a[L];
			if(d*cnt[L]<=k)
				k-=d*cnt[L],cnt[L+1]+=cnt[L],L++;
			else{
				int tmp=a[L]+k/cnt[L];
				printf("%d\n",a[R]-tmp);
				return 0;
			}
		}
		else{
			LL d=a[R]-a[R-1];
			if(d*cnt[R]<=k)
				k-=d*cnt[R],cnt[R-1]+=cnt[R],R--;
			else{
				int tmp=a[R]-k/cnt[R];
				printf("%d\n",tmp-a[L]);
				return 0;
			}
		}
	}
	puts("0");
	return 0;
}
