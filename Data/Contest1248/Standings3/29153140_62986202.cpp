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
int n,m,a[maxn],sum,ans;
int main(){
    read(n);
    for(rg int i=1;i<=n;i++)read(a[i]),ans+=a[i];
    sort(a+1,a+n+1);
    for(rg int i=1;i<=n/2;i++)sum+=a[i];
    if(n%2==0)printf("%lld\n",1ll*(ans-sum)*(ans-sum)+1ll*sum*sum);
    else {
	long long now=1ll*(ans-sum)*(ans-sum)+1ll*sum*sum;
	sum+=a[n/2+1];
	printf("%lld\n",max(now,1ll*(ans-sum)*(ans-sum)+1ll*sum*sum));
    }
}
