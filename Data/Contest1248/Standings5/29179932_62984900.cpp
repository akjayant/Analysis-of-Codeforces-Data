#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long a[maxn];
int main(){
	int n;
	scanf("%d",&n);
	long long sum1=0,sum2=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if( i < n/2 ) sum1+=a[i];
		else sum2+=a[i];
	}
	cout<<sum1*sum1+sum2*sum2<<endl;
	return 0;
}
