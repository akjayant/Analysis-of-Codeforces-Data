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
        string string1,string2;
        ip(string1>>string2);
        vector<bool> v(n);
        f(i,n)
            if(string1[i]==string2[i])
                v[i] = true;

        ll XX = 0;
        f(i,n)XX += !v[i];
        if(!XX)
            op("Yes");
        else if(XX!=2)
            op("No");
        else
        {
            vector<ll> seq;
            f(i,n)
                if(!v[i])
                    seq.pb(i);
            swap(string1[seq[0]], string2[seq[1]]);
            if(string1==string2)op("Yes");
            else op("No");
        }
    }
}
