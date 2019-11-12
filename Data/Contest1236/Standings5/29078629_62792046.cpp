#include<cstdio>
#include<algorithm>
using namespace std;
int T,A,B,C;
int Solve1(int a,int b,int c){
	int ret=0;
	while(b>=1&&c>=2)b-=1,c-=2,ret+=3;
	while(a>=1&&b>=2)a-=1,b-=2,ret+=3;
	return ret;
}
int Solve2(int a,int b,int c){
	int ret=0;
	while(a>=1&&b>=2)a-=1,b-=2,ret+=3;
	while(b>=1&&c>=2)b-=1,c-=2,ret+=3;
	return ret;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&A,&B,&C);
		printf("%d\n",max(Solve1(A,B,C),Solve2(A,B,C)));
	}
}