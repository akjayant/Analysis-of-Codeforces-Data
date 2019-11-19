#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;++a)
#define Dor(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
using namespace std;
const int N=100007;
int n,t,P[N],D[N],hd[N],nt[N<<1],to[N<<1];
LL S[3][N],ans[N];
void fly(int u,int f) {
	P[++t]=u;
	for(int i=hd[u];i;i=nt[i])
	if(to[i]!=f) fly(to[i],u);
}
int main() {
	scanf("%d",&n);
	For(i,0,2)
		For(j,1,n) scanf("%lld",&S[i][j]);
	For(i,1,n-1) {
		int x,y;
		scanf("%d%d",&x,&y),++D[x],++D[y];
		nt[i*2-1]=hd[x],hd[x]=i*2-1,to[i*2-1]=y;
		nt[i*2]=hd[y],hd[y]=i*2,to[i*2]=x;
	}
	For(i,1,n)
	if(D[i]>2) {
		puts("-1");
		return 0;
	}
	For(i,1,n)
	if(D[i]==1) {
		fly(i,-1);
		break;
	}
	int a=0,b=1,c=2,d=0,e=1,f=2;
	LL A=0,B=0,C=0,D=0,E=0,F=0;
	For(i,1,n) {
		int u=P[i];
		A+=S[a][u];
		B+=S[b][u];
		C+=S[c][u];
		D+=S[d][u];
		E+=S[e][u];
		F+=S[f][u];
		a=(a+1)%3,b=(b+1)%3,c=(c+1)%3;
		d=(d+2)%3,e=(e+2)%3,f=(f+2)%3;
	}
	if(A<B&&A<C&&A<D&&A<E&&A<F) {
		printf("%lld\n",A);
		int a=0;
		For(i,1,n) {
			ans[P[i]]=a+1;
			a=(a+1)%3;
		}
		For(i,1,n) printf("%lld ",ans[i]);
		return 0;
	}
	if(B<C&&B<D&&B<E&&B<F) {
		printf("%lld\n",B);
		int b=1;
		For(i,1,n) {
			ans[P[i]]=b+1;
			b=(b+1)%3;
		}
		For(i,1,n) printf("%lld ",ans[i]);
		return 0;
	}
	if(C<D&&C<E&&C<F) {
		printf("%lld\n",C);
		int c=2;
		For(i,1,n) {
			ans[P[i]]=c+1;
			c=(c+1)%3;
		}
		For(i,1,n) printf("%lld ",ans[i]);
		return 0;
	}
	if(D<E&&D<F) {
		printf("%lld\n",D);
		int d=0;
		For(i,1,n) {
			ans[P[i]]=d+1;
			d=(d+2)%3;
		}
		For(i,1,n) printf("%lld ",ans[i]);
		return 0;
	}
	if(E<F) {
		printf("%lld\n",E);
		int e=1;
		For(i,1,n) {
			ans[P[i]]=e+1;
			e=(e+2)%3;
		}
		For(i,1,n) printf("%lld ",ans[i]);
		return 0;
	}
	printf("%lld\n",F);
	f=2;
	For(i,1,n) {
		ans[P[i]]=f+1;
		f=(f+2)%3;
	}
	For(i,1,n) printf("%lld ",ans[i]);
	return 0;
}