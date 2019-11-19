#include<stdio.h>
#include<algorithm>
using namespace std;
int n,sh[100005];
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&sh[i]);
	}
	sort(sh+1,sh+1+n);
	long long a1=0,a2=0;
	for(int i=1;i<=n/2;i++){
		a1+=sh[i];
	}
	for(int i=n/2+1;i<=n;i++){
		a2+=sh[i];
	}
	printf("%I64d",a1*a1+a2*a2);
}
