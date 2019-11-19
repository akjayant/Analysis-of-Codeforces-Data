#include<bits/stdc++.h>
typedef int LL;
typedef double DL;
const LL maxn=1e6+9;
LL Read(){
	LL x(0),f(1); char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-') f=-1; c=getchar();
	}
	while(c>='0' && c<='9'){
		x=(x<<3)+(x<<1)+c-'0'; c=getchar();
	}
	return x*f;
}
LL n,m;
LL a[19][19];
DL f[19][19];
int main(){
	n=m=10;
	for(LL i=1;i<=n;++i){
		for(LL j=1;j<=m;++j) a[i][j]=Read();
	}
	f[1][1]=0; f[1][2]=f[1][3]=f[1][4]=6; f[1][5]=6; f[1][6]=6;
	for(LL i=1;i<=n;++i){
//		printf("%d\n",i);
		if(i&1){
//			printf("%d:",i);
			for(LL j=1;j<=m;++j){
				if(i==1 && j<=6) continue;
				for(LL k=1;k<=6;++k){
					if(i==1){
						f[i][j]+=f[i][j-k];
					}else{
						if(k<=(j-1)){
							if(a[i][j-k]) f[i][j]+=std::min(f[i-a[i][j-k]][j-k],f[i][j-k]);
							else f[i][j]+=f[i][j-k];
						}else{
							LL x(i-1),y(1+(k-j));
							if(a[x][y]){
//								printf("(%d,%d)\n",i,j);
								f[i][j]+=std::min(f[x-a[x][y]][y],f[x][y]);
							}
							else f[i][j]+=f[x][y];
						}
					}
				}
				f[i][j]/=6.0; f[i][j]+=1.0;
//			            printf("%.1lf ",f[i][j]);
			}
		}else{
			for(LL j=m;j>=1;--j){
				for(LL k=1;k<=6;++k){
				    if(k<=(m-j)){
					    if(a[i][j+k]) f[i][j]+=std::min(f[i-a[i][j+k]][j+k],f[i][j+k]);
					    else f[i][j]+=f[i][j+k];
				    }else{
					    LL x(i-1),y(m-(k-(m-j+1)));
					    if(a[x][y]){
//					    	printf("(%d,%d)\n",i,j);
					    	f[i][j]+=std::min(f[x-a[x][y]][y],f[x][y]);
						}
					    else f[i][j]+=f[x][y];
				    }
			    }
			    f[i][j]/=6.0; f[i][j]+=1.0;
//			    printf("%.1lf ",f[i][j]);
			}
//			for(LL j=1;j<=m;++j) printf("%.1lf ",f[i][j]);
		}
//		puts("");
	}
	printf("%.10lf\n",f[10][1]);
	return 0;
}