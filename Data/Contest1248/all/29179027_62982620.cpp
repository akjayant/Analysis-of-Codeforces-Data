#include <bits/stdc++.h>
using namespace std;
#define inc(i,d) for (int i=0;i<d;i++)
typedef long long ll;

ll a[100010];

int main(){
	int n; cin>>n;
	inc(i,n)scanf("%lld",a+i);
	sort(a,a+n);
	ll s1=0,s2=0;
	for (int i=0;i<n/2;i++) s1+=a[i];
	for (int i=n/2;i<n;i++) s2+=a[i];
	printf("%lld\n",s1*s1+s2*s2);
	return 0;
}
