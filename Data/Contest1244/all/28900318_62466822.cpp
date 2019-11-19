#include<bits/stdc++.h>
using namespace std;
int t,a,b,c,d,n,x,y;
int main(){
    scanf("%d",&t);
    while(t--){
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&n);
	x=a/c+((a%c==0)?0:1);
	y=b/d+((b%d==0)?0:1);
	if(x+y>n) printf("-1\n");
	else printf("%d %d\n",x,n-x);
    }
}
