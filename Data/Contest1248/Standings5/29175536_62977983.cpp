#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,ji1,ou1,ji2,ou2;
int tmp;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		ji1=ou1=ji2=ou2=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&tmp);
			if(tmp%2){
				ji1++;
			}
			else{
				ou1++;
			}
		}
		scanf("%lld",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&tmp);
			if(tmp%2){
				ji2++;
			}
			else{
				ou2++;
			}
		}
		printf("%lld\n",ji1*ji2+ou1*ou2);
	}
	return 0;
}