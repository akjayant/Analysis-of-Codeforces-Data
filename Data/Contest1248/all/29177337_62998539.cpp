#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

typedef long long LL;
const int MAXN = 1e5+5;
const LL mod = 1e9+7;
int n,m;

LL sol(int N){
	if(N <=3) return N;
	LL res = 2;
	LL pre = 1;	
	for(int i = 2;i<N;i++){
		LL tm = res;
		res =(res+pre)%mod;
		pre = tm;
	}
	return res;
}

int main(){
	cin>>n>>m;
	LL x = sol(n);
	LL y = sol(m);
	LL ans = ((x+y-1)+mod)%mod;
	ans = (ans*2)%mod;
	cout<<ans<<endl;	
	return 0;
}