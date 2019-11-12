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
const int N=1005;
int n,a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int T=read();
	while(T--){
		n=read();
		For(i,1,n) a[i]=read();
		sort(a+1,a+n+1,cmp);
		int ans=0;
		For(i,1,n) ans=max(ans,min(i,a[i]));
		writeln(ans);
	}
}