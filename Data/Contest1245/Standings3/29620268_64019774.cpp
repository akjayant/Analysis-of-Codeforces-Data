#include<bits/stdc++.h>
#define cp complex<double>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int MAXINF=2147483647;
const int INF=0x3f3f3f3f;
const ll INFLL=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-6;

int read(){
	int s=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	s=s*f;
	return s;
}

ll readll(){
	ll s=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){if (c=='-') f=-1;c=getchar();}
	while (c>='0' && c<='9'){s=s*10+c-'0';c=getchar();}
	s=s*f;
	return s;
}

int n,a,b,c,chu[105];
char ch[105];

/*
R: rock     a
P: paper    b
S: scissor  c
*/

void print(int x){
	if (x==1){
		printf("R");
	}
	else if (x==2){
		printf("P");
	}
	else{
		printf("S");
	}
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T=read();
	while (T--){
//		n=read();
		scanf("%d",&n);
//		a=read();b=read();c=read();
		scanf("%d%d%d",&a,&b,&c);
		scanf("%s",ch+1);
		int s=0;
		for (register int i=1;i<=n;++i){
			if (ch[i]=='S'){
				if (a){
					a--;
					s++;
					chu[i]=1;
				}
				else{
					chu[i]=0;
				}
			}
			else if (ch[i]=='R'){
				if (b){
					b--;
					s++;
					chu[i]=2;
				}
				else{
					chu[i]=0;
				}
			}
			else{
				if (c){
					c--;
					s++;
					chu[i]=3;
				}
				else{
					chu[i]=0;
				}
			}
		}
		if (s<(n+1)/2){
			printf("NO");
		}
		else{
			printf("YES\n");
			for (register int i=1;i<=n;++i){
				if (chu[i]){
					print(chu[i]);
				}
				else{
					if (a){
						a--;
						printf("R");
					}
					else if (b){
						b--;
						printf("P");
					}
					else{
						c--;
						printf("S");
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}

