#include<bits/stdc++.h>
using namespace std;
int a[100005];
typedef long long ll;
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ll sum = 0;
	for(int i = 1; i <= n/2; i++){
		sum+=1LL*a[i];
	}
	ll sum1 = 0;
	for(int i = n/2+1; i <= n; i++){
		sum1+=1LL*a[i];
	}
	printf("%lld\n",sum1*sum1+sum*sum);
	return 0;
}