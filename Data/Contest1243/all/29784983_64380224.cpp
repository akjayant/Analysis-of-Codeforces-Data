#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
			if(a[n-i+1]>=i){
				printf("%d\n",i);
				break;
			}
		}
	}
}