#include<cstdio>
#define ll long long
int main(){
	int ca;
	scanf("%d",&ca);
	while(ca--){
		ll n,m,tmp;
		ll odd1=0,odd2=0;
		scanf("%lld",&n);
		for(int i=0;i<n;i++){
			scanf("%lld",&tmp);
			if(tmp%2==1)odd1++;
		}
		scanf("%lld",&m);
		for(int i=0;i<m;i++){
			scanf("%lld",&tmp);
			if(tmp%2==1)odd2++;
		}
		printf("%lld\n",odd1*odd2+(n-odd1)*(m-odd2));
	}
}