#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005];
int main(){
	scanf("%d",&k);
	while(k--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			if(a[i]>=n-i){
				printf("%d\n",n-i);
				break;
			}
		}
	}
}
