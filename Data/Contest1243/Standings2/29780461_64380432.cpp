#include<bits/stdc++.h>
using namespace std;
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long
inline ll read(){
	ll x=0;char ch=getchar();bool f=0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=1;
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	return f?-x:x;
}
void write(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>=10) write(x/10);putchar(x%10+'0');
}
void writeln(ll x){write(x);puts("");}
void writep(ll x){write(x);putchar(' ');}
const int N=1e4+5;
int n;
char s[N],t[N];
int main(){
	int T=read();
	while(T--){
		n=read();
		scanf("%s%s",s+1,t+1);
		int cnt=0;
		For(i,1,n) if(s[i]!=t[i]) cnt++;
		if(cnt==0){puts("Yes");continue;}
		if(cnt!=0&&cnt!=2){puts("No");continue;}
		int pos1=0,pos2=0;
		For(i,1,n){
			if(s[i]!=t[i]){
				if(!pos1) pos1=i;
				else pos2=i;
			}
		}
		if(s[pos1]!=s[pos2]||t[pos1]!=t[pos2]) puts("No");
		else puts("Yes");
	}
}