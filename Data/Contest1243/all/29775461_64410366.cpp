#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	LL n;scanf("%lld",&n);
	if(n%2==0){
		for(int i=0;i<=63;i++){
			if(n==(1ll<<i)){
				printf("2\n");return 0;
			}
		}
		printf("1\n");return 0;
	}
	set<LL>se;
	for(LL i=2;i*i<=n;i++){
		if(n%i) continue;
		se.insert(i);	
		se.insert(n/i);	
	}
	if(se.size()==0){printf("%lld\n",n);}
	else{
		//printf("%lld\n",*se.begin());
		LL p=*se.begin();
		LL tmp=0;
		while(n%p==0) n/=p;
		if(n==1) printf("%lld\n",p);
		else printf("1\n"); 
	}
	return 0;
}