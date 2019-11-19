#include<iostream>
#include<cmath>
#include<algorithm>
#define mod 1000000007
using namespace std;
long long n,m,a[100005];
int main(){
	cin>>n>>m;
	a[1]=1,a[2]=2;
	for(int i=3;i<=100000;++i){
		a[i]=(a[i-1]+a[i-2])%mod;
	}
	
	cout<<(2*((a[n]+a[m])%mod)%mod-2+mod)%mod;
} 