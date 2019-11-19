#include<iostream>
#include<cstdio>
#include<set>
const int N=1e6+5;
int a[N];
int main() {
    int n;long long k;
    scanf("%d%lld",&n,&k);
    long long tot=1LL*n*(n+1)/2;
    if(tot>k) return !printf("-1");
    k-=tot;
    std::set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    for(int i=1;i<=n;i++) {
        int mx=n;
        if(k<n-i) mx=int(k+i);
        auto it=s.upper_bound(mx);
        --it;
        a[i]=*it;
        s.erase(it);
        k-=std::max(0,a[i]-i);
        tot+=std::max(0,a[i]-i);
        //printf("%d\n",mx);
    }
    printf("%lld\n",tot);
    for(int i=1;i<=n;i++) printf("%d%c",i," \n"[i==n]);
    for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}
