///Ma-ia-hii
///Ma-ia-huu
///Ma-ia-hoo
///Ma-ia-haa
///X4

///Alo, Salut, Sunt Eu, un Haiduc
///Si Te Rog, Iubirea mea Primeste Fericirea
///Alo, Alo, Sunt Eu, Picasso
///Ti-am dat beep
///Si Sunt Voinic
///Dar Sa Stii Nu-ti Cer Nimic

///Vrei sa pleci dar nu ma, nu ma iei
///nu ma, nu ma iei, nu ma, nu ma, nu ma iei
///Nu Ma, Nu Ma Iei, nu ma, nu ma, nu ma iei
///Chipul tau si dragostea din tei
///Mi-amintesc de ochii tai

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define DIM (long long)100007
#define INF (long long)1000000007
#define fi first
#define se second
#define x1 sfhshfd
#define y1 sfhs321321hfd
#define glhf ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define GG cout << " OPANA " << endl;

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pairll;
typedef tree<ll,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> SATANA;



ll t,n,m,res1,res2;
ll mod=1000000007;
ll binpow(ll x, ll k){
    if(k==0) return 0;
    ll res=1;
    while(k>0){
        if(k&1) res=(res*x)%mod;
        x=(x*x)%mod;
        k/=2;
    }
    return res;
}

ll dp[100007][2];
int main()
{
    glhf;
    cin >> n >> m;
    ll opa=0;
    dp[1][1]=1;
    for(int i=2; i<=m; i++){
        dp[i][1]=(dp[i-1][1]+dp[i-1][2])%mod;
        dp[i][2]=(dp[i-1][1])%mod;
        opa=(opa+dp[i][2])%mod;
    }
    ll k=opa*2;

    //k=binpow(2,m-1);

    ll type1=1,type2=0,z;
    for(int i=2; i<=n; i++){

        z=type1;
        type1=(type1+type2)%mod;
        type2=z%mod;
    }

    cout << (((type1+type2)*2)%mod+(k%mod)+mod)%mod << endl;



























    return 0;
}
