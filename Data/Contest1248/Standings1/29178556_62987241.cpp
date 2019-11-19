#include<bits/stdc++.h>
#define db double
#define ll long long
#define ev edge[i].v
#define pb push_back
#define INF 1000000007
#define Rep(i,l,r) for(int i=(l);i<=(r);++i)
#define RepD(i,r,l) for(int i=(r);i>=(l);--i)
#define RepG(i,x) for(int i=head[x];i;i=edge[i].next)
using namespace std;

const int N=1e5+5;

ll a[N];

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ll n,sum=0,tmp=0;
	scanf("%I64d",&n);
	Rep(i,1,n) scanf("%I64d",&a[i]),sum+=a[i];
	sort(a+1,a+n+1);
	Rep(i,1,n/2) tmp+=a[i];
	printf("%I64d\n",sum*sum-2*tmp*(sum-tmp));
	return 0;
}
