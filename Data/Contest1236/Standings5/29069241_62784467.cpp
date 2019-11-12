/*----------AV1502-----------*/
#include "bits/stdc++.h"

using namespace std;

#define TEST(T) int T; sci(T) ; while(T--)
#define int long long
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ins insert
#define pii pair<int,int>
#define all(V) V.begin(),V.end()
#define clr(V,val) memset(V,val,sizeof(V))
#define rep(X,A,N,C) for(X=A;X<=N;X+=C)
#define rept(X,A,N,C) for(X=A;X>=N;X-=C)
#define sci(X) scanf("%d",&X)
#define scl(X) scanf("%lld",&X)
#define scs(X) scanf("%s",&X)
#define pfi(X) printf("%d",X)
#define pfl(X) printf("%lld",X)
#define pfs(X) printf("%s",X)
#define sp printf(" ")
#define nxt printf("\n")
#define endl "\n";
 
const int MX=1e6 + 5;
 
const int INF=1e9;
 
const int M=1000000007;
void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    ans+=min(b,c/2);
    b-=ans;
    ans+=min(a,b/2);
    cout<<ans*3LL<<endl;
    return ;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
	return 0;
}