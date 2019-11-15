#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<stack>
#include<vector>
#include<deque>
#include<climits>

#define mem(a) memset((a),0,sizeof((a)));
#define mod 1000000007
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define tv t[p].val
#define tl t[p].l
#define tr t[p].r
#define eps 1e-5
#define maxa 1005
using namespace std;

int read(){
	int xyz135=0,paage46=1;
	char cc1=getchar();
	while(cc1>'9'||cc1<'0'){
		if(cc1=='-')paage46=-1;
		cc1=getchar();
	}
	while(cc1>='0'&&cc1<='9'){
		xyz135=xyz135*10+cc1-'0';
		cc1=getchar();
	}
	return xyz135*paage46;
}
inline void read(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=((x<<1)+(x<<3))+c-'0';
		c=getchar();
	}
	return ;
}
inline void w1(int x){
	if(x){
		w1(x/10);
		putchar(x%10+48);
	}
	return ;
}
inline void write(int x){
	if(x)w1(x);
	else putchar('0');
	return ;
}
int to[maxa],nxt[maxa],top=1,h[maxa];
void psh(int u,int v){
	to[++top]=v;nxt[top]=h[u];h[u]=top;
	to[++top]=u;nxt[top]=h[v];h[v]=top;
	return ;
}
int n;
int a,b,c;
char cc[maxa],d[maxa];
 
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n>>a>>b>>c;
		scanf("%s",cc+1);
		memset(d,' ',sizeof(d));
		int ans=0;
		for(int i=1;i<=n;i++){
			if(cc[i]=='R'&&b>0)ans++,b--,d[i]='P';
			if(cc[i]=='S'&&a>0)ans++,a--,d[i]='R';
			if(cc[i]=='P'&&c>0)ans++,c--,d[i]='S';
		}
		if(ans>=(n+1)/2){
			puts("YES");
			for(int i=1;i<=n;i++){
				if(d[i]!=' ')putchar(d[i]);
				else if(a>0)putchar('R'),a--;
				else if(c>0)putchar('S'),c--;
				else putchar('P');
			}putchar(10);
		}
		else puts("NO");
	}
	return 0;
}