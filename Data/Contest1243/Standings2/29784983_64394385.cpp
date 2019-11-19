#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	scanf("%I64d",&n);
	int r=sqrt(n)+1;
	int cnt=0;
	ll ans=1;
	for(int i=2;i<r;i++){
		if(n%i==0){
			cnt++;
			ans=i;
			while(n%i==0) n/=i;
		}
	}
	if(n!=1){
		cnt++;
		ans=n;
	}
	if(cnt>1){
		printf("1\n");
	}else{
		printf("%I64d\n",ans);
	}
}