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
int t,n,ans;char a[maxn];
int main(){
    read(t);
    while(t--){
	read(n),scanf("%s",a+1);ans=n;int l=0,r=0;
	for(rg int i=1;i<=n;i++){
	    if(a[i]=='1'&&!l)l=i;
	    if(a[i]=='1')r=i;
	}
	if(l)ans=max(n*2-(l-1)*2,r*2);
	printf("%d\n",ans);
    }
}
