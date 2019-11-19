#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
inline int read(){
	int sum(0);char ch(getchar());
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum;
}
int t,a,b,c,d,k,x,y;
int main(){
	t=read();
	while(t--){
		a=read(),b=read(),c=read(),d=read(),k=read();
		x=(a-1)/c+1,y=(b-1)/d+1;
		if(x+y>k)printf("%d\n",-1);
		else printf("%d %d\n",x,y);
	}
}