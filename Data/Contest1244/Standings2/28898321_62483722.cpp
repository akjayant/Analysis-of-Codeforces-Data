#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
inline int read(){
	int f=1,ans=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}
const int MAXN=100001;
int n,k,A[MAXN];
signed main(){
//	freopen("make.in","r",stdin);
	n=read(),k=read();
	for(int i=1;i<=n;i++) A[i]=read();sort(A+1,A+n+1);
	int Mid=A[(n+1)/2],res=0;for(int i=1;i<=n;i++) res+=abs(A[i]-Mid);if(res<=k){printf("0\n");return 0;}
	int L=1,R=n;res=0;
	while(1){
		while(L<=n&&A[L]==A[L+1]) L++;
		while(R<=n&&A[R]==A[R-1]) R--;
		int cL=L,cR=n-R+1;
		if(cL>=cR){
			int now=res+(cR*(A[R]-A[R-1]));
			if(now<=k){R--;res=now;continue;}
			int tt=k-res;int e=tt/cR;
			int ll=A[L],rr=A[R]-e;
			printf("%lld\n",rr-ll);return 0;
		}else{
			int now=res+(cL*(A[L+1]-A[L]));
			if(now<=k){L++;res=now;continue;}
			int tt=k-res;int e=tt/cL;
			int ll=A[L]+e,rr=A[R];
			printf("%lld\n",rr-ll);return 0;
		}
	}return 0;
}
