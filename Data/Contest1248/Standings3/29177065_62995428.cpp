#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+5;
ll f[N],s[N];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	f[1]=2;f[2]=2;s[1]=2;s[2]=4;
	for(int i=3;i<=100000;i++){
		f[i]=(f[i-1]+f[i-2])%mod;
		s[i]=(s[i-1]+f[i])%mod;
	}
	printf("%lld\n",(f[n]+f[n-1]+s[m-1])%mod);//
	return 0;
}