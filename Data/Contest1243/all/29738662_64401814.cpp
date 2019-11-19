#include<bits/stdc++.h>
#include<algorithm>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define is insert
#define rep1(i,a,b) for(long long i=a;i<=b;i++)
#define mp make_pair
#define mh make_heap
#define F first
#define S second
//#define fin cin
//#define fout cout
#define file ifstream fin("input.txt");ofstream fout("output.txt");
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ALL(x) (x).begin(), (x).end()
#define int long long
typedef long long ll;
#define lb lower_bound
#define ub uper_bound
#define bs lower_bound
typedef pair<ll,ll> pairs;
typedef vector<ll> vi;
typedef vector<pairs> vpair;

void solve()
{
    ll n;cin>>n;
    set<ll>se;
    for(ll i=2;(i*i)<=n;i++)
    {
        if(n%i==0)
        {
            se.is(i);
            if(n/i!=i)
                se.is(n/i);
        }
    }

        if(se.size()==0)
        {
            cout<<n<<endl;
        }
        else
        {
            ll gcd=0;
            for(auto x:se)
            {
                gcd=__gcd(gcd,x);
            }
            cout<<gcd<<endl;
        }
        return ;
}
int32_t main()
{
    fast;
    ll t=1;
    //cin>>t;
    fr(t)
    solve();
   return 0;
}

