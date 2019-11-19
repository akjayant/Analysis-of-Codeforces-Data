#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
typedef long long       ll;
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define forr(i, b, e)     for (ll i = b; i < e; i++)
#define forit(i,b)        for( auto i=b.begin();i!=b.end();i++)
ll faster_in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
 
using namespace std;
using namespace __gnu_pbds;
 
typedef pair<ll, ll>  ii;
typedef pair<ll,ii> iii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
const ll INF = ll(1e9 + 7);
const double EPS = 1e-9;
const double PI = acos(-1);
#define tam 400056
#define offset 200056
 
const ll MOD=1e9+7;
vector<ll> grafo[tam];
ll x[tam],y[tam];
ll precio[tam],arrpa[tam];
ll findpa(ll num)
{
    if (num==arrpa[num])
        return num;
    else return arrpa[num]=findpa(arrpa[num]);
}
int main()
{
    forr(i,0,tam)
        arrpa[i]=i;
    std::ios::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin>>n;
    forr(i,1,n+1)
    {
        cin>>x[i]>>y[i];
    }
    vector<iii> lst;
    ll costo;
    forr(i,1,n+1)
    {
        cin>>costo;
        lst.pb(mp(costo,mp(0,i)));
    }
    forr(i,1,n+1)
    {
        cin>>precio[i];
    }
    forr(i,1,n+1)
    {
        forr(j,i+1,n+1)
        {
            costo=abs(x[i]-x[j])+abs(y[i]-y[j]);
            costo*=(precio[i]+precio[j]);
            lst.pb(mp(costo,mp(i,j)));
        }
    }
    sort(lst.begin(),lst.end());
    ll tot=0;
    ll iz,der;
    vector<ll> v1;
    vector<ii> v2;
    forr(i,0,lst.size())
    {
        costo=lst[i].F;
        iz=lst[i].S.F;
        der=lst[i].S.S;
        if (findpa(iz)!=findpa(der)){
            if (iz==0)
            {
                v1.pb(der);
            }
            else {
                v2.pb(mp(iz,der));
            }
            arrpa[findpa(iz)]=findpa(der);
            tot+=costo;
        }
    }
    cout<<tot<<endl;
    cout<<v1.size()<<endl;
    for(ll nodo:v1)
    {
        cout<<nodo<<" ";
    }
    cout<<endl;
    cout<<v2.size()<<endl;
    for(auto par:v2)
    {
        cout<<par.F<<' '<<par.S<<endl;
    }
}
// 