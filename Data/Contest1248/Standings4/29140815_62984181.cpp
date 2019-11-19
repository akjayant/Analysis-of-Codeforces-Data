#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define pb push_back
#define mp make_pair

int main(){
	int n,i;
	scanf("%d",&n);
	ll a[100002];
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	ll ans=0,p=0,q=0;
	sort(a,a+n);
	for(i=0;i<n/2;i++){
		q+=a[i];
	}
	for(i=n/2;i<n;i++){
		p+=a[i];
	}
	ans = p*p+q*q;
	printf("%lld\n",ans );
	return 0;
}