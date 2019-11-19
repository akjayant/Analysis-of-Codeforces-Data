#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long 
#define N 35
LL f[N+5][2][2];
int T,l,r;
LL calc(LL a,LL b){
	if(a<0||b<0)return 0;
	f[N][0][0]=1;
	for(int i=N-1;i>=0;--i){
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k)
				f[i][j][k]=0;
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k){
				 bool nexj=j|((a&(1ll<<i))),nexk=k|((b&(1ll<<i)));
			//	 cout<<"? "<<i<<" "<<nexj<<" "<<nexk<<endl;
				 f[i][nexj][nexk]+=f[i+1][j][k];
				 if((a&(1ll<<i))|j)
				 	f[i][j][nexk]+=f[i+1][j][k];
				if(((b>>i)&(1ll))|k)
					f[i][nexj][k]+=f[i+1][j][k];
			}
		}
	LL res=0;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			res+=f[0][i][j];
	return res;
}
signed main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&l,&r);
		printf("%lld\n",calc(r,r)-calc(l-1,r)*2ll+calc(l-1,l-1));
	}
	return 0;
}