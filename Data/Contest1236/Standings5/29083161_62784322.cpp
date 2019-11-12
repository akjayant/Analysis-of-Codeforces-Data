#include <bits/stdc++.h>

using namespace std;

int main(){
	int T; scanf("%d",&T); while(T--){
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		int ans = 0;
		for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) if(i <= a && 2*i+j <= b && 2*j <= c) ans = max(ans, 3*i+3*j);
		printf("%d\n",ans);
	}
	
	return 0;
}

