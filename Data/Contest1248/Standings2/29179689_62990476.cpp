#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
#define LL long long int
#define p 1000000007

LL fib(LL n) {
	LL f[2]={1,1};
	for(int i=2;i<=n;++i) {
		f[i%2] += f[(i+1)%2];
		f[i%2] %= p;
	}
	return f[n%2];
}

int main() {
	LL n,m;
	cin>>n>>m;
	cout<<( 2*(fib(n)+fib(m)-1) )%p<<"\n";
}