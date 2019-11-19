#include <bits/stdc++.h>
using namespace std;
long long n;
int a[1000050];
int main(){
	scanf("%I64d",&n);
	long long t=n;
	a[0]=0;
	int m=sqrt(n);
	//cout<<m<<endl;
	for(int i=2;i<=m;i++){
		if(n%i==0){
			a[++a[0]]=i;
			while(n%i==0) n/=i;
		}
		if(n==1) break;
	}
	if(n!=1&&n!=t) printf("1\n");
	else if(a[0]==0) printf("%I64d\n",n);
	else if(a[0]==1) printf("%d\n",a[1]);
	else printf("1\n");
	return 0;
}