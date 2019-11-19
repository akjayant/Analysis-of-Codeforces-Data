#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#define fo(i,l,r) for (auto i=l,_end=r;i<=_end;++i)
#define fd(i,l,r) for (auto i=l,_end=r;i>=_end;--i)
#define FI(x) freopen(x,"r",stdin)
#define FO(x) freopen(x,"w",stdout)
using ll=long long;
using namespace std;

const int n=10;
int to[n*n+10];
double f[n*n+10];

int xy2i(int x,int y) {
	return x*n+(x&1?n-y-1:y);
}

int main() {
//	FI("e.txt");
	fo(x,0,n-1) fo(y,0,n-1) {
		int a;
		scanf("%d",&a);
		assert(a<=x);
		to[xy2i(x,y)]=xy2i(x-a,y);
	}
//	fo(i,0,n-1) fo(j,0,n-1) printf("%2d%c",xy2i(i,j)," \n"[j==n-1]);
	f[0]=0.;
	fo(i,1,6) f[i]=6;
	/*fo(i,1,6) {
		f[i]=6;
		fo(j,0,i-1) f[i]+=f[j];
		f[i]/=i;
		printf("f[%d]=%lf\n",i,f[i]);
	}*/
	fo(i,7,n*n-1) {
		f[i]=6;
		fo(j,1,6) f[i]+=min(f[i-j],f[to[i-j]]);
		f[i]/=6;
	}
	printf("%.10lf\n",f[n*n-1]);
}


