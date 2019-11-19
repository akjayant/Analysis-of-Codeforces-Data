#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int n,m,T,x;
int main(){
	scanf("%d",&T);
	for (;T--;){
		long long f1=0,f2=0,s1=0,s2=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++){
			scanf("%d",&x);
			if (x%2==1) f1++;
			else s1++;
		}
		scanf("%d",&m);
		for (int i=1;i<=m;i++){
			scanf("%d",&x);
			if (x%2==1) f2++;
			else s2++;
		}
		long long ans=f1*f2+s1*s2;
		cout << ans << "\n";
	}
	return 0;
} 
