#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int cnt[2];
long long ans=0;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        cnt[1]=cnt[0]=ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]%2]++;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)scanf("%d",&b[i]),ans+=(long long) cnt[(b[i]%2)];
        printf("%lld\n",ans);
    }
}
