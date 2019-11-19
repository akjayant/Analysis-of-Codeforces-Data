#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int a, b, c, d, k, rpc, rpn;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
		rpn=ceil((float)a/(float)c);
		rpc=ceil((float)b/(float)d);
	
		if(rpn+rpc>k){
			printf("-1\n");
		}
		else{
			printf("%d %d\n", rpn, rpc);
		}
	}
	return 0;
}