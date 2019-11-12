#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i, b, e)     for (ll i = b; i < e; i++)
#define forr(i, b, e)     for (int i = b; i < e; i++)
ll faster_in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
 
using namespace std;
//using namespace __gnu_pbds;
const ll MOD=1e9+7;
ll pot(ll b,ll e)
{
    b%=MOD;
    ll res=1;
    while(e)
    {
        if (e&1)res*=b,res%=MOD;
        b*=b,b%=MOD;
        e/=2;
    }
    return res;
}
int main()
{
    //cout<<pot(3,3)<<endl;
    std::ios::sync_with_stdio(false); cin.tie(0);
    ll n,m;
    cin>>n>>m;
    cout<<pot((pot(2,m)-1)+MOD,n)<<endl;
}
// PLUS ULTRA!