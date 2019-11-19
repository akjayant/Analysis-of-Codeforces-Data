#include<bits/stdc++.h>
#define pr(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define Toggle(n,i) (n^(1<<i))
#define Check(n,i) (n&(1<<i))
#define Set(n,i) (n|(1<<i))
#define Reset(n,i) (n&(~(1<<i)))
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define me(arr,val) memset(arr,val,sizeof arr)
#define inf 10e8
#define infl LLONG_MAX
#define mod 1000000007
#define f first
#define s second
#define  g(t,a)  (get<a>(t))
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//int dx[]={+1,-1,0,0};//vertical horizontal
//int dy[]={0,0,+1,-1};//vertical horizontal
//int dx[]={+1,+1,-1,-1,+2,-2,+2,-2};//knights move
//int dy[]={+2,-2,+2,-2,+1,+1,-1,-1};//knights move
//int dx[]={+1,-1,0,0,+1,+1,-1,-1};//vertical horizontal diagonal
//int dy[]={0,0,+1,-1,-1,+1,+1,-1};//vertical horizontal diagonal
using namespace std;
using namespace __gnu_pbds;
/*typedef tree<int, null_type,less<int>, rb_tree_tag,
             tree_order_statistics_node_update>indexed_set;
for set use above*/
typedef tree<pair<int,int>, null_type,less_equal<pair<int, int>>, rb_tree_tag,
tree_order_statistics_node_update> indexed_multiset;


int main()
{
    ll n;
    scanf("%lld",&n);
    vector<ll>div;
    ll i;
    for(i=2;i*i<n;++i)
    {
        if(n%i==0)
        {
            div.push_back(i);
            div.push_back(n/i);
        }
    }
    if(i*i==n)
    {
        div.push_back(i);
    }
    ll ans=n;
    for(int i=0;i<div.size();++i)
    {
        ans=__gcd(ans,div[i]);
    }
    printf("%lld",ans);
    return 0;
}

