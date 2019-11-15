// Etavioxy
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cassert>
#define re register
#define ll long long
#define il inline
#define rep(i,s,t) for(re int i=(s);i<=(t);i++)
#define rev_rep(i,s,t) for(re int i=(s);i>=(t);i--)
#define each(i,u) for(int i=head[u];i;i=bow[i].nxt)
#define pt(ch) putchar(ch)
#define pti(x) printf("%d",x)
#define ptll(x) printf("%I64d",x)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
// c_ints
il int ci(){
	re char ch;int f=1;
	while(!isdigit(ch=getchar()))f= ch=='-'?-1:1 ;
	re int x= ch^'0';
	while(isdigit(ch=getchar()))x=(x*10)+(ch^'0');
	return f*x;
}
enum{N=64};
char s[N],t[N];
int step[N][2];
int main(){
	int T=ci();
	while( T-- ){
		int n=ci();
		scanf("%s%s",s+1,t+1);
		int m= 0;
		bool fail= 0;
		rep(i,1,n) if( s[i]!=t[i] ){
			int nxt=0;
			rep(j,i+1,n) if( s[i]==s[j] ){
				nxt=j; break;
			}
			if( nxt==0 ){
				int nxt2=0;
				rep(j,i+1,n) if( t[j]==s[i] ){
					nxt2=j; break;
				}
				if( nxt2==0 ){ puts("NO"); fail=1; break; }
				m++;
				step[m][0]=i+1;
				step[m][1]=nxt2;
				swap(s[step[m][0]],t[step[m][1]]);
				nxt= i+1;
			}
			m++;
			step[m][0]=nxt;
			step[m][1]=i;
			swap(s[step[m][0]],t[step[m][1]]);
		}
		if( fail ) continue;
		puts("YES");
		printf("%d\n",m);
		rep(i,1,m){
			printf("%d %d\n",step[i][0],step[i][1]);
		}
	}
	return 0;
}
