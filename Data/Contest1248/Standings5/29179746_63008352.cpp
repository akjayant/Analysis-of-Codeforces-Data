#include<bits/stdc++.h>
using namespace std;
int n,m;
typedef long long ll;
const ll mod = 1e9+7;
ll a[100005];
int main(){
	a[1] = 2;a[2] = 4;
	scanf("%d%d",&n,&m);
	for(int i = 3; i <= 100000; i++)
	a[i] = (a[i-2]+a[i-1])%mod;
	printf("%lld\n",(a[n]+a[m]-2+mod)%mod);
	return 0;
}