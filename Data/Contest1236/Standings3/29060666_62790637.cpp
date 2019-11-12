#include <bits/stdc++.h>
using namespace std;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
const int M = 1e9 + 7;
int n,m;
int power(int base,int to){
	int ret = 1;
	while(to){
		if(to&1)ret = ret*1LL*base%M;
		to>>=1;
		base = base*1LL*base%M;
	}
	return ret;
}
int main(){
// 	freopen("input.txt","r",stdin);
	scanf("%d%d",&n,&m);	
	cout << power((power(2,m) - 1 + M)%M,n) << endl;
}