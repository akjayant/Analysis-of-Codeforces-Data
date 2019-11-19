#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 +5;
long long a1,a2,b1,b2;

int main(){
	int T;scanf("%d",&T);
	while(T--){
		a1 = a2 = b1= b2 = 0;
		int n;scanf("%d",&n);
		int cnt;
		for(int i = 1 ; i <= n ; i++){
			scanf("%d",&cnt);
			if(cnt % 2 == 1)a1++;
			else a2++;
		}
		int m;scanf("%d",&m);
		for(int i = 1 ; i <= m ; i++){
			scanf("%d",&cnt);
			if(cnt % 2 == 1)b1++;
			else b2++;
		}
		printf("%I64d\n",a1*b1+a2*b2);
	}
}