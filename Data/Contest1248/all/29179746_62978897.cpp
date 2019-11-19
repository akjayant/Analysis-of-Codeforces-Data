#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b;
		scanf("%d",&a);
		int x = 0,y = 0;
		for(int i = 1; i <= a; i++){
			long long int p;
			scanf("%d",&p);
			if(p%2==0) x++;
			else y++;
		}
		int x1 = 0,y1 = 0;
		scanf("%d",&b);
		for(int i = 1; i <= b; i++){
			int p;
			scanf("%d",&p);
			if(p%2==0)x1++;
			else y1++;
		}
		printf("%lld\n",1LL*x1*x+1LL*y1*y);
	}
	return 0;
} 