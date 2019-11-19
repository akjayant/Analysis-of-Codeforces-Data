#include<bits/stdc++.h>
typedef long long LL;
const LL maxn=1e6+9,mod=1e9+7;
const LL dx[]={0,-1,0,0,1},dy[]={0,0,-1,1,0};
inline LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3)+(x<<1)+c-'0'; c=getchar();
	}return x*f;
}
LL n,m,ans,nw;
LL sum[100][100],a[100][100],A[maxn];
inline bool Check(LL x,LL y){
	return x>=1 && x<=n && y>=1 && y<=m;
}
void Dfs(LL x,LL y){
//	printf("(%d,%d)\n",x,y);
	if(y==m+1){
		ans++; return;
	}
	if(x==n+1){
		Dfs(1,y+1); return;
	}
//	a[x][y]=0;
    LL xx(x),yy(y);
    {
    	a[x][y]=0;
        LL fl=1; LL cnt(0);
        for(LL i=1;i<=2;++i){
        	LL xx(x+dx[i]),yy(y+dy[i]);
        	if(!Check(xx,yy)) continue;
        	if(!a[xx][yy]) ++cnt;
        	if(!a[xx][yy] && sum[xx][yy]==1) fl=0;
		}
		if(cnt==2) fl=0;
		if(fl==1){
			for(LL i=1;i<=2;++i){
        	LL xx(x+dx[i]),yy(y+dy[i]);
        	    if(!Check(xx,yy)) continue;
        	    if(!a[xx][yy]) ++sum[xx][yy],++sum[x][y];
		    }
		    Dfs(x+1,y);
		    for(LL i=1;i<=2;++i){
        	LL xx(x+dx[i]),yy(y+dy[i]);
        	    if(!Check(xx,yy)) continue;
        	    if(!a[xx][yy]) sum[xx][yy]--,--sum[x][y];
		    }
		}
	}
	{
    	a[x][y]=1;
//        xx=x-1; yy=y;
        LL fl=1; LL cnt(0);
        for(LL i=1;i<=2;++i){
        	LL xx(x+dx[i]),yy(y+dy[i]);
        	if(!Check(xx,yy)) continue;
        	if(a[xx][yy]) ++cnt;
        	if(a[xx][yy] && sum[xx][yy]==1) fl=0;
		}
		if(cnt==2) fl=0;
		if(fl==1){
			for(LL i=1;i<=2;++i){
        	LL xx(x+dx[i]),yy(y+dy[i]);
        	    if(!Check(xx,yy)) continue;
        	    if(a[xx][yy]) ++sum[xx][yy],++sum[x][y];
		    }
		    Dfs(x+1,y);
		    for(LL i=1;i<=2;++i){
        	LL xx(x+dx[i]),yy(y+dy[i]);
        	    if(!Check(xx,yy)) continue;
        	    if(a[xx][yy]) sum[xx][yy]--,--sum[x][y];
		    }
		}
	}
}
inline bool CC(){
	for(LL i=1;i<=n;++i){
		for(LL j=1;j<=m;++j){
			LL cnt(0);
			for(LL k=1;k<=4;++k){
				LL x(i+dx[k]),y(j+dy[k]);
				if(a[x][y]==a[i][j]) ++cnt;
			}
			if(cnt>=2) return false;
		}
	}
	return true;
}
void Dfs2(LL x,LL y){
	if(y==m+1){
		ans+=CC(); return;
	}
	if(x==n+1){
		Dfs2(1,y+1); return;
	}
	a[x][y]=0;
	Dfs2(x+1,y);
	a[x][y]=1;
	Dfs2(x+1,y);
}
int main(){
//	T=10000;
//	while(true){
//	memset(a,-1,sizeof(a));
	n=Read(); m=Read();
	ans=0;
	if(n<=2 && m<=2){
		Dfs(1,1);
//		Dfs2(1,1);
	    printf("%lld\n",ans);
	    return 0;
	}
	if(n==1 || m==1){
//		Dfs(1,1);
        if(n==1) std::swap(n,m);
        ans=(2);
        LL P1(0),P2(2);
        for(LL i=2;i<=n;++i){
//        	printf("(%lld,%lld:%lld)\n",P1,P2,ans);
        	(ans+=P2)%=mod; LL K(P1); P1=P2; P2=(K+P2)%mod;
		}
//		Dfs2(1,1);
	    printf("%lld\n",ans);
	    return 0;
	}
//	puts("233");
//	return 0;

	A[2]=2; A[3]=4;
	for(LL i=4;i<=100000;++i) A[i]=(A[i-1]+A[i-2])%mod;
	nw=6;
    for(LL i=3;i<=n;++i){
    	nw=(nw+A[i-1])%mod;
	}
	for(LL i=3;i<=m;++i) nw=(nw+A[i-1])%mod;
	printf("%lld\n",nw);
//    }
}