#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int SIZE=1e5+50;
ll arr[SIZE];
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&arr[i]);
	}
	sort(arr+1,arr+1+n);
	ll sum1=0;ll sum2=0;
	for(int i=1;i<=n/2;i++){
		sum1+=arr[i];
	}
	for(int i=n/2+1;i<=n;i++){
		sum2+=arr[i];
	}
	printf("%lld\n",sum1*sum1+sum2*sum2);
}