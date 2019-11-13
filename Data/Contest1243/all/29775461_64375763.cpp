#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int a[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			int pos=lower_bound(a+1,a+n+1,i)-a;
			if(pos>n||pos<1) continue;
			if(n-pos+1>=i) ans=i;
		}
		printf("%d\n",ans);
	} 
	
	
	
	
	return 0;
} 