#include<bits/stdc++.h>
#define INF 0x7fffffff
#define pi acos(-1,0)
#define e 2.718281828459
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}

ll t;
ll a1,a2,b1,b2,in;
ll n,m;

int main(){
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
    
    scanf("%lld",&t);
    
    while(t--){
    	scanf("%lld",&n);
    	a1=0;a2=0;b1=0;b2=0;
    	for(int i=1;i<=n;i++){
    		scanf("%lld",&in);
    		if(in%2==1) a1++;
    		else a2++;
		}
		scanf("%lld",&m);
		for(int i=1;i<=m;i++){
			scanf("%lld",&in);
			if(in%2==1) b1++;
    		else b2++;
		}
		ll ans=b2*a2+b1*a1;
		printf("%lld\n",ans);
	}
    return 0;
}
