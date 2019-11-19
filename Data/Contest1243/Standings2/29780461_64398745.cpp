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
int main(){
	ll n=read(),alb=0;
	int cnt=0;
	for(ll i=2;i*i<=n;i++) if(n%i==0){
		cnt++;alb=i;
		while(n%i==0) n/=i;
	}
	if(n!=1) cnt++,alb=n;
	if(cnt==1) cout<<alb;
	else cout<<1;
}