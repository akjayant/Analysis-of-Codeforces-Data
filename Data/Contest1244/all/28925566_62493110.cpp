#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
#define int long long
void read(int &x){
    char ch;bool ok;
    for(ok=0,ch=getchar();!isdigit(ch);ch=getchar())if(ch=='-')ok=1;
    for(x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());if(ok)x=-x;
}
#define rg register
const int maxn=2e5+10;
int n,k,tot,a[maxn],now,ans;
signed main(){
    read(n),read(k);
    for(rg int i=1;i<=n;i++)read(a[i]);
    sort(a+1,a+n+1);
    int l=1,r=n;
    while(l<=r){
	int now=a[l+1]-a[l],now1=a[r]-a[r-1];tot++;
	if((now+now1)*tot>k){
	    ans=a[r]-a[l]-(k/tot);
	    break;
	}
	else k-=(now+now1)*tot;
	l++,r--;
    }
    printf("%lld\n",max(ans,0ll));
}
