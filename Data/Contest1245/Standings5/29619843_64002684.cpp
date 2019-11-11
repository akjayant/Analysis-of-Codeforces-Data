#include <cstdio>
#include <cstdlib>
#define N 1001
#define rnt register int
using namespace std;
int T,a,b;
int getgcd(int x,int y){
	if(x%y==0) return y;
	else return getgcd(y,x%y);
}
int main(){
	scanf("%d",&T);
	Work:if(T){
		scanf("%d%d",&a,&b);
		if(a>b){int c=b;b=a;a=c;}
		if(getgcd(a,b)==1) puts("Finite");
		else puts("Infinite");
		--T;goto Work;
	}
	return 0;
}
