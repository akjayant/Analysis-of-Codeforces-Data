#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int N=1005;
int n,mx,mi,ans;
char a[N];
int main(){
	int T;scanf("%d",&T);
	for(;T;--T){
		scanf("%d",&n);mx=0;mi=n;
		cin>>a+1;
		for(int i=1;i<=n;++i)if(a[i]=='1'){
			mi=min(mi,i);
			mx=max(mx,i);
		}
		if(mx==0){printf("%d\n",n);continue;}
		mi=n-mi+1;
		ans=max(mx,mi);
		printf("%d\n",ans*2);
	}
	return 0;
}
