#include<bits/stdc++.h>
using namespace std;
void solve(){
	int a,b,c,d,k;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
	for(int i=0;i<=k;++i)if(i*c>=a&&d*(k-i)>=b){
		printf("%d %d\n",i,k-i);
		return;
	}puts("-1");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--)solve();
}