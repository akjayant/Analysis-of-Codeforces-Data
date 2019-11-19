#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=2;
ll tmp[N][N],res[N][N];
void multi(ll a[][N],ll b[][N],int n){
    memset(tmp,0,sizeof(tmp));
    for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
    		for(ll k=0;k<n;k++){
        		tmp[i][j]+=(a[i][k]*b[k][j])%mod;
        		}
        	tmp[i][j]=tmp[i][j]%mod;
      	}
   	}
    for(ll i=0;i<n;i++)
        for(ll j=0;j<n;j++)
        	a[i][j]=tmp[i][j];
}
void Pow(ll a[][N],ll m,int n){
    memset(res,0,sizeof(res));
    for(ll i=0;i<n;i++) res[i][i]=1;
    while(m){
	    if(m&1)multi(res,a,n);
        multi(a,a,n);
        m>>=1;
    }
}
int main(){
    ll m,n;
    ll ans;
    ll a[N][N];
    scanf("%lld%lld",&n,&m);
    a[0][0]=1,a[0][1]=1,a[1][0]=1,a[1][1]=0;
	Pow(a,max(m,n)+1,2);
	ans=res[1][0]*2-2;
	a[0][0]=1,a[0][1]=1,a[1][0]=1,a[1][1]=0;
	Pow(a,min(m,n)+1,2);
	ans+=res[1][0]*2;
	ans%=mod;
	printf("%lld\n",ans);
   	return 0;
}