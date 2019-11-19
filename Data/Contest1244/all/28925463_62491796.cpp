#include<bits/stdc++.h>
using namespace std;
const int M=1e6+5;

int n;long long K;

int A[M];
void Solve()
{
    // long long tmp=K;
    for(int i=1;i<=n;i++)A[i]=i;
    for(int i=1;i<=n;i++)K-=i;
    if(K<0){puts("-1");return;}
    for(int i=1;i<=n/2;i++)
    {
        int d=min(K,(long long)n-2*i+1);
        // printf("%d d=%d\n",i,d);
        K-=d;swap(A[i],A[i+d]);
    }
    long long ans=0;
    for(int i=1;i<=n;i++)ans+=max(i,A[i]);
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++)printf("%d ",i);puts("");
    for(int i=1;i<=n;i++)printf("%d ",A[i]);puts("");
    // for(int i=1;i<=n;i++)tmp-=max(A[i],i);if(tmp)puts("#");
}

int main()
{
    scanf("%d%lld",&n,&K);
    Solve();
    return 0;
}