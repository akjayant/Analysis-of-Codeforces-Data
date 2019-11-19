#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int n,p[maxn];
long long l,r,x=0,y=0,ans;
inline int read(){
	int x=0,f=1;
	char c;
	do{c=getchar();if(c=='-') f*=-1;}while(!isdigit(c));
	while(isdigit(c)){x=(x<<3)+(x<<1)+'c'-'0';c=getchar();}
	return f*x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&p[i]);}
	sort(p+1,p+n+1);
	l=1,r=n;
	while(l<r){
		x+=p[l];
		y+=p[r];
		l++;r--;
	}
	if(l==r){y+=p[(l+r)/2];}
	ans=x*x+y*y;
	printf("%lld\n",ans);
}