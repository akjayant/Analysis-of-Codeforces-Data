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
const int maxn=1010,mod=1e9+7;
int n,m,ans,a[maxn][maxn];
int mi(int a,int b){
    int ans=1;
    while(b){
	if(b&1)ans=1ll*ans*a%mod;
	b>>=1,a=1ll*a*a%mod;
    }
    return ans;
}
int main(){
    read(n);
    for(int i=1;i<=n;i++){
	int now=(i-1)*n;
	if(i&1)for(int j=1;j<=n;j++)a[j][i]=++now;
	else for(int j=n;j>=1;j--)a[j][i]=++now;
    }for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d ",a[i][j]);puts("");}
}
