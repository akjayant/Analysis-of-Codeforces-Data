#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
int d1[35],d2[35],cnt;
inline ll calc(int l,int r){
	if(l<0)return 0;
	memset(d1,0,sizeof(d1));
	memset(d2,0,sizeof(d2));
	reg int t=l;cnt=0;
	while(t)d1[++cnt]=t&1,t>>=1;
	cnt=0;t=r;
	while(t)d2[++cnt]=t&1,t>>=1;
	reg ll f=0,g=0,h=0,flg=1;
	for(reg int i=cnt;i;i--){
		f*=3;
		if(d1[i])f+=g*2;
		if(d2[i])f+=h*2;
		if(d1[i]&&d2[i])f+=flg;
		if(!d1[i])g*=2;
		if(d2[i])g+=flg;
		if(!d2[i])h*=2;
		if(d1[i])h+=flg;
		if(d1[i]&&d2[i])flg=0;
	}
	return f+g+h+flg;
}
int main(){
	reg int T;scanf("%d",&T);
	while(T--){
		static int L,R;
		scanf("%d%d",&L,&R);
		printf("%lld\n",calc(R,R)-calc(L-1,R)*2+calc(L-1,L-1));
	}
	return 0;
}