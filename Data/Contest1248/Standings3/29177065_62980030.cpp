#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,m;
int main(){
	scanf("%d",&t);
	while(t--){
		int cnt1=0,cnt2=0;
		scanf("%d",&n);
		int a;
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			if(a%2)cnt1++;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d",&a);
			if(a%2)cnt2++;
		}
		printf("%lld\n",ll(cnt1)*cnt2+ll(n-cnt1)*(m-cnt2));
	}
	return 0;
}