#include<bits/stdc++.h>
using namespace std;

const int N=1010;
int T,n;
int a[N];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n,cmp);	
		int mmax=0;
		for(int i=1;i<=n;i++) mmax=max(mmax,min(i,a[i]));
		printf("%d\n",mmax);
	}
}