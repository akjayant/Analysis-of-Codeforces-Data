#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	char c=getchar();
	int f=1;
	x=0;
	while(c<'0' || c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int main(){
	int i,j,k,m,n;
	int T;
	read(T);
	while(T--){
		int x,y,z;
		read(x);read(y);read(z);
		int tmp=min(y,z/2);
		int ans=tmp*3;
		y-=tmp;z-=tmp*2;
		if(y){
			tmp=min(x,y/2);
			ans+=tmp*3;
			x-=tmp;y-=tmp*2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
