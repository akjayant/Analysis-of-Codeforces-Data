#include<bits/stdc++.h>
#define N 1000010
#define ll long long
using namespace std;
int a[N],b[N];
int main(){
	int n;ll k,kk;
	scanf("%d%lld",&n,&k);
	kk=k;
	for(int i=1;i<=n;i++)a[i]=b[i]=i;
	k-=(ll)n*(n+1)/2;
	if(k<0)return 0*printf("-1\n");
	int x1=1,x2=n;
	while(x1<x2&&k>=x2-x1)k-=x2-x1,swap(b[x1],b[x2]),x1++,x2--;
	// cout<<"!!"<<x1<<" "<<x2<<" "<<k<<endl;
	if(k&&x1<x2)swap(b[x1],b[x1+k]),k=0;
	printf("%lld\n",kk-k);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	printf("\n");
	return 0;
}