#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;

int n;
long long K,A[M];

void Solve()
{
    sort(A+1,A+n+1);
    long long ans=A[n]-A[1];
    int l=1,r=n,lc=1,rc=1;
    while(true)
    {
        long long dr=min(K/rc,A[r]-A[r-1]);
        A[r]-=dr;ans-=dr;K-=rc*dr;r--;rc++;
        // printf("dr = %lld %lld,%lld\n",dr,A[r],A[r+1]);
        if(A[r]!=A[r+1] || l==r)break;
        long long dl=min(K/lc,A[l+1]-A[l]);
        A[l]+=dl;ans-=dl;K-=lc*dl;l++;lc++;
        // printf("dl = %lld %lld,%lld\n",dl,A[l],A[l-1]);
        if(A[l]!=A[l-1] || l==r)break;
    }
    printf("%lld\n",ans);
}

int main()
{
    scanf("%d%lld",&n,&K);
    for(int i=1;i<=n;i++)scanf("%lld",&A[i]);
    Solve();
    return 0;
}