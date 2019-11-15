#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
int a,b,T;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if(__gcd(a,b)!=1)printf("Infinite\n");
		else printf("Finite\n");
	}
	return 0;
}
