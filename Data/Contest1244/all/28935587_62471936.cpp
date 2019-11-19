#include<bits/stdc++.h>
using namespace std;
char a[1003];
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		scanf("%s", a);

		int cmax=-1;
		for(int i=0;i<n;i++){
			if(a[i]=='1'){
				cmax=max(cmax, 2*(n-i));
				break;
			}
		}
		for(int i=n-1;i>=0;i--){
			if(a[i]=='1'){
				cmax=max(cmax, 2*(1+i));	
				break;
			}
		}
		printf("%d\n", max(cmax, n));
	}
	return 0;
}