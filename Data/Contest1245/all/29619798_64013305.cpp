#include<stdio.h>
#include<stack>
std::stack<char>S;
int a,b,c,n,t,d,e,f;
inline int Min(int a,int b){return a<b?a:b;}
char g[100002];
int main(){
	scanf("%d",&t);
	while(t--){d=e=f=0;
		scanf("%d%d%d%d%s",&n,&a,&b,&c,g+1);
		for(int i=1;i<=n;i++)d+=g[i]=='S',e+=g[i]=='R',f+=g[i]=='P';
		if(Min(a,d)+Min(b,e)+Min(c,f)<n+1>>1){printf("NO\n");continue;}
		for(int i=d;i<a;i++)S.push('R');
		for(int i=e;i<b;i++)S.push('P');
		for(int i=f;i<c;i++)S.push('S');puts("YES");
		for(int i=1;i<=n;i++){
			bool f=0;
			if(g[i]=='S'&&a)a--,printf("R"),f=1;
			if(g[i]=='R'&&b)b--,printf("P"),f=1;
			if(g[i]=='P'&&c)c--,printf("S"),f=1;
			if(!f)printf("%c",S.top()),S.pop();
		}puts("");
	}
}