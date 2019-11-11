#include<bits/stdc++.h>
#define LL long long
#define MAXN 300005
#define INF (1<<25)
#define P int(998244353)
using namespace std;

int N,M;
int a,b;

int main(){
	
	ios::sync_with_stdio(0);
	
	int T;
	cin>>T;
	
	while(T--){
		cin>>a>>b;
		if(__gcd(a,b)==1) cout<<"Finite"<<endl;
		else cout<<"Infinite"<<endl;
	}
	
	
	
	return 0;
}