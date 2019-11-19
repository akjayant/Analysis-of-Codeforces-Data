#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define mp make_pair
#define pb push_back
#define xmod 1000000007
using namespace std;

ll t,n,od1,ev1,od2,ev2,x,m;
ll ans;
int main(){
	scanf("%lld",&t);
	for (int i=1;i<=t;i++){
		scanf("%lld",&n);
		od1=0; ev1=0; od2=0; ev2=0; ans=0;
		for (int j=1;j<=n;j++){
			scanf("%lld",&x);
			if (x%2 == 0)
			ev1++;
			else
			od1++;
		}
		scanf("%lld",&m);
		for (int j=1;j<=m;j++){
			scanf("%lld",&x);
			if (x%2 == 0)
			ev2++;
			else
			od2++;
		}
		ans=od1*od2+ev1*ev2;
		printf("%lld\n",ans);
	}
    return 0;
}