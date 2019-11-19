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

ll n,a[100005],sum1,sum;
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n/2;i++){
		sum1+=a[i];
	}
	printf("%lld\n",(sum-sum1)*(sum-sum1)+sum1*sum1);
    return 0;
}