#include<bits/stdc++.h>
using namespace std;
int t,sum[3],x,n;
long long ans;
int main(){
    scanf("%d",&t);
    while(t--){
	sum[1]=sum[0]=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	    scanf("%d",&x);
	    sum[x%2]++;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	    scanf("%d",&x);
	    ans=ans+sum[x%2];
	}
	printf("%lld\n",ans);
	ans=0;
    }
}
