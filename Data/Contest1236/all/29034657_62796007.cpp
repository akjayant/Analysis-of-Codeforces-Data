#include <bits/stdc++.h>
#define rap(i,s,n) for(int i=s;i<=n;i++)
using namespace std;
int main(){
	int n; scanf("%d",&n);
	rap(i,1,n){
		int k=0;
		rap(j,1,n){
			if(k) printf("%d ",j*n-i+1);
			else printf("%d ",(j-1)*n+i);
			k=!k;
		}
		printf("\n");
	}
	return 0;
}