#include<cstdio>
#include<algorithm>
using std::min; 
int main(){
	int t,a,b,c;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&c);
		int ans=0;
		for(int i=0;i<=a&&2*i<=b;++i){
			int tb=b-2*i,tans=min(tb,c/2)+i;
			if(tans>ans) ans=tans;
		}
		printf("%d\n",3*ans);
	} 
	return 0;
}