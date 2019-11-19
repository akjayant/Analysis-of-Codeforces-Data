//ZJ_MRZ's Code
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>
#define N 100010
#define Mod 1000000007
using namespace std;
int n,m;
long long f[N];
int main() {
	cin>>n>>m;
	f[0]=0;
	f[1]=2;
	f[2]=4;
	for(int i=3;i<=max(n,m);i++) {
		f[i]=(f[i-1]+f[i-2])%Mod;
	}
	long long ans=(f[m]+f[n]-2)%Mod;
	cout<<ans<<endl;
	return 0;
}