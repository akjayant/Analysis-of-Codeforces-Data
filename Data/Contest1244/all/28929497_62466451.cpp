#include<cstdio>
#include<iostream>
using namespace std;
int t,a,b,c,d,k,x,y;
int main(){
	scanf("%d",&t);
while (t--){
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
	x=a/c; if (x*c<a) x++;
	y=b/d; if (y*d<b) y++;
	if (x+y>k) puts("-1");
	else printf("%d %d\n",x,y);
}
	return 0;
}