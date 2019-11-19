#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	int x=0,y=0;
	for(int i=1;i<=n;i++){
		if(i<=n/2){
			x+=a[i];
		}else{
			y+=a[i];
		}
	}
	printf("%lld\n",1ll*x*x+1ll*y*y);
	return 0;
}