#include<cstdio>
int Gcd(int a,int b){
	if((a%b)==0) return b;
	return Gcd(b,a%b);
}
int main(){
	int T,a,b;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&a,&b);
		if(Gcd(a,b)==1) puts("Finite");
		else puts("Infinite");
	}
} 