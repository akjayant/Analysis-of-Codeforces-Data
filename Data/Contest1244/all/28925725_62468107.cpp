#include<cstdio>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a,b,c,d,K;
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&K);
		int cnt1=a/c,cnt2=b/d;
		cnt1+=a%c!=0;cnt2+=b%d!=0;
		if(cnt1+cnt2<=K)printf("%d %d\n",cnt1,cnt2);
		else puts("-1");
	}
	return 0;
}