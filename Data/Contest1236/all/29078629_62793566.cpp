#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
const int MOD=1000000007;
long long N,M,Sum=1;
LL quick_Pow(LL x,LL y){
	if(y==0)return 1;
	if(y==1)return x;
	if(y%2)return (x*quick_Pow((x*x)%MOD,y/2))%MOD;
	return quick_Pow((x*x)%MOD,y/2);
}
int main(){
	scanf("%lld%lld",&N,&M);
	Sum=(quick_Pow(2,M)-1+MOD)%MOD;
	printf("%lld\n",quick_Pow(Sum,N));
}
