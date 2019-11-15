#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	int n;
	int a[1010];
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		int ans=1;
		for (int i=0;i<n;i++){
			ans=max(ans,min(a[i],n-i));
		}
		printf("%d\n",ans);
	}
	
	return 0;
}