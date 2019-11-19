#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unrolled-loops")
using namespace std;
/*---------------------Define--------------------*/
#define inp "TestCode.inp"
#define out "TestCode.out"
#define pi acos(-1)
#define endl '\n'
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define hash lolo
#define y1 MustDefeatGKT1
/*-----------------------------------------------*/
const long long mod=1e9+7;
const long long mod2=1e9+9;
const long long INF=1e12;
const long long oo=1e18+7;
int test=1;
/*-----------------------------------------------*/
void Varvalian()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    ifstream *fi = new ifstream (inp);
    ofstream *fo = new ofstream (out);
    if(*fi)
    {
        cin.rdbuf( fi->rdbuf() );
        cout.rdbuf( fo->rdbuf() );
    }

}
void db();
#define int long long
/*-------------------Global----------------------*/
ll n;
vector<ll> di;
/*------------------Functions--------------------*/
ll gcd(ll a, ll b)
{
    ll r;
    while(b>0)
    {
        r = a%b;
        a=b;b=r;
    }
    return a;
}
ll lcm(ll a, ll b)
{
    return a/gcd(a,b)*b;
}
/*-----------------------------------------------*/

void In()
{
    cin>>n;
}

void Solve()
{
    In();

    for(int i=2;i<=sqrt(n);i++)
        if(n/i*i==n)
        {
            //cout<<i<<endl;
            di.pb(i);
            di.pb(n/i);
        }
    sort(di.begin(), di.end());
    //for(int i=0;i<di.size();i++)
    //    cout<<di[i]<<" ";
    //cout<<endl;
    ll ans = 1;
    for(int i=0;i<di.size();i++)
        ans = lcm(ans, di[i]);
    //cout<<ans<<endl;
    cout<<n/ans;
}

void db()
{

}

int32_t main()
{
    Varvalian();

    //cin>>test;while(test--)
    Solve();
}
