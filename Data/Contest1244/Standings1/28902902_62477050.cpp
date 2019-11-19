#include<bits/stdc++.h>
using namespace std;
long long n,p,w,d,x,y,g;
bool fl;
int main(){
	scanf("%lld %lld %lld %lld",&n,&p,&w,&d);
	for(int i=0;i<w&&p>=0;++i){
		if(p%w==0){
			x=i;y=p/w;
			fl=1;
			break;
		}
		p-=d;
	}
	if(!fl||x+y>n)puts("-1");
	else printf("%lld %lld %lld\n",y,x,n-x-y);
}
