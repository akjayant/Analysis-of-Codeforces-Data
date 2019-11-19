#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){

		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		sort(a+1,a+n+1);
		long long x=0,y=0;
		for(int i=1;i<=n;i++){
			if(i<=n/2)x+=a[i];
			else y+=a[i];
		}
	//	printf("%lld %lld\n",x,y);
		printf("%lld\n",x*x+y*y);

}