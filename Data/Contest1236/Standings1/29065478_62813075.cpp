#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 1e5;

int N, M, A[MAXN+10], ans1[MAXN+10], ans2[MAXN+10];

int main()
{
    int i, j;

    scanf("%d%d", &N, &M);
    for(i=1; i<=M; i++) scanf("%d", &A[i]);

    if(N==1) return !printf("0");

    map<int, int> M1;
    for(i=1; i<=N; i++) M1[i]=1;
    for(i=1; i<=M; i++)
    {
        if(M1.find(i)!=M1.end()) M1[i+1]+=M1[i], M1.erase(i);
        if(M1.find(A[i]+i)!=M1.end()) M1[A[i]+i+1]+=M1[A[i]+i], M1.erase(A[i]+i);
    }
    if(M1.find(M+1)!=M1.end()) M1[M+1+1]+=M1[M+1], M1.erase(M+1);

    map<int, int> M2;
    for(i=1; i<=N; i++) M2[i]=1;
    for(i=1; i<=M; i++)
    {
        if(M2.find(N-i+1)!=M2.end()) M2[N-i+1-1]+=M2[N-i+1], M2.erase(N-i+1);
        if(M2.find(A[i]-i)!=M2.end()) M2[A[i]-i-1]+=M2[A[i]-i], M2.erase(A[i]-i);
    }
    if(M2.find(N-(M+1)+1)!=M2.end()) M2[N-(M+1)+1-1]+=M2[N-(M+1)+1], M2.erase(N-(M+1)+1);

    i=1;
    for(auto it : M1) for(j=1; j<=it.second; j++, i++) ans1[i]=it.first-M-1;

    i=1;
    for(auto it : M2) for(j=1; j<=it.second; j++, i++) ans2[i]=it.first+M+1;


    //for(i=1; i<=N; i++) printf("%d ", ans1[i]); printf("\n");
    //for(i=1; i<=N; i++) printf("%d ", ans2[i]);

    ll ans=0;
    for(i=1; i<=N; i++) ans+=ans2[i]-ans1[i]+1;
    printf("%lld", ans);
}
