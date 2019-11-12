#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T,n,m,p1[256],r1[200],r2[200];
char a[53],b[53];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",a+1);
		scanf("%s",b+1);
		memset(p1,0,sizeof(p1));
		for(int i=1;i<=n;++i)
			++p1[a[i]],++p1[b[i]];
		bool ok=1;
		for(int i='a';i<='z'&&ok;++i)
			if(p1[i]&1) ok=0;
		if(!ok){puts("No"); continue;}
		puts("Yes"); m=0;
		for(int i=1;i<=n;++i) if(a[i]!=b[i]){
			for(int j=i+1;j<=n;++j){
				if(a[j]==a[i]){
					r1[++m]=j;
					r2[m]=i;
					swap(a[j],b[i]);
					break;
				}
				if(b[j]==a[i]){
					r1[++m]=i+1;
					r2[m]=j;
					swap(a[i+1],b[j]);
					r1[++m]=i+1;
					r2[m]=i;
					swap(a[i+1],b[i]);
					break;
				}
			}
		}
		printf("%d\n",m);
		for(int i=1;i<=m;++i) printf("%d %d\n",r1[i],r2[i]);
	}return 0;
}
