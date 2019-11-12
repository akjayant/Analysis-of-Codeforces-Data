#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
#define rg register
const int maxn=100;
int a,b,c,T,sum;
int main(){
    read(T);
    while(T--){
	read(a),read(b),read(c);sum=a+b+c;
	int now=min(b,c/2);c-=now*2,b-=now;
	int w=min(a,b/2);b-=w*2,a-=w;
	printf("%d\n",sum-a-b-c);
    }
}
