#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rg register
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
const int maxn=1e5+10;
int T,n,m,q[maxn],p[maxn];
int main(){
    read(T);
    while(T--){
	read(n);int sum1=0,sum2=0;
	for(rg int i=1;i<=n;i++)read(p[i]),sum1+=p[i]%2;
	read(m);
	for(rg int i=1;i<=m;i++)read(q[i]),sum2+=q[i]%2;
	printf("%lld\n",1ll*sum1*sum2+1ll*(n-sum1)*(m-sum2));
    }
}
