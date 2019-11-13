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

int calculate(int num,int p)
{
    int res=1;
    while(p>0)
    {
        if(p%2==0)
        {
            num=(num*num)%M;
            p=p/2LL;
        }
        else
        {
            res=(res*num)%M;
            p--;
        }
    }
    return res;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    int c=(calculate(2,m)-1+M)%M;
    //cout<<c<<endl;
    cout<<calculate(c,n);
    return ;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
	return 0;
}