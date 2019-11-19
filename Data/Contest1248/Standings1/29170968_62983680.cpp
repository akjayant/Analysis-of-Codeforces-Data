#include<stdio.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#include<algorithm>
using namespace std;
int n,a[110000];//a[11000]!!!!!
long long s1,s2;
int main(){
	scanf("%d",&n);
	fo(i,1,n) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	fo(i,1,n/2) s1+=a[i];
	fo(i,n/2+1,n) s2+=a[i];
	printf("%I64d\n",s1*s1+s2*s2);
	return 0;
}