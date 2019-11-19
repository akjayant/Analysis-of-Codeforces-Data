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
const int maxn=1e5+10;
int t,a,b,c,d,k;
int main(){
    read(t);
    while(t--){
	read(a),read(b),read(c),read(d),read(k);
	int now1=a/c+(a%c!=0),now2=b/d+(b%d!=0);
	if(now1+now2>k)printf("-1\n");
	else printf("%d %d\n",now1,now2);
    }
}
