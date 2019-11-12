#include<iostream>
using namespace std;
#define p 1000000007
#define LL unsigned long long int

LL power(LL x,LL e) {
	if(e==0) return 1;
	if(e==1) return x%p;
	LL ans=power(x,e/2);
	ans = (ans*ans)%p;
	if(e%2) ans=(ans*x)%p;
	return ans;
}

int main() {
	LL n,m;
	cin>>n>>m;
	LL ans=power(2,m);
	ans = (ans+p-1)%p;
	ans = power(ans,n);
	cout<<ans<<"\n";
}