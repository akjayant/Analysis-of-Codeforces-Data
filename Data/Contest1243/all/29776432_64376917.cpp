//DEEPANSHU SAXENA(saxenad765)
#include <bits/stdc++.h>
#define ll long long
#define array(x,n) (x,x+n)
#define all(c) (c).begin(),(c).end()
#define VECTOR(v) cout << '>' << #v << ':' ; vector_out(v);
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ip(x) cin>>x
#define op(x) cout<<x<<endl
#define ops(x) cout<<x<<" "
#define odd(x) (x&1)
#define even(x) (!x&1)
#define cpresent(a,x) (find(all(a),x) != (a).end())
#define it(a,i) for(typeof((a).begin() i = (a).begin(); i != (a).end(); i++)
#define present(a,x) ((a).find(x) != (a).end())
#define fbei(i,x,y,z) for(ll i=x;i<=y;i+=z)
#define fbe(i,x,y) for(ll i=x;i<=y;i++)
#define f(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define mp(x,y) make_pair(x,y)
#define GCD(x,y) __gcd(x,y)
using namespace std;
//using codechef ide;
//Deepanshu Saxena
inline void filehandling()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
vector<ll> vector_in(ll n)
{
    vector<ll> v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    return v;
}
void vector_out(vector<ll> v)
{
    for(ll i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
}
ll vector_sum(vector<ll> v)
{
    ll sum;
    for(ll i=0;i<v.size();i++)
    sum+=v[i];
    return sum;
}
int main()
{
    fast
    filehandling();
    ll Test=1;
    ip(Test);
    while(Test--)
    {
        ll n;
        ip(n);
        ll array1[n];
        f(i,n)
        ip(array1[i]);
        sort(array1,array1+n);
        ll z=0;
        f(i,n)
        if(array1[i]>=n-i)z=max(z,n-i);
        op(z);
    }
}
