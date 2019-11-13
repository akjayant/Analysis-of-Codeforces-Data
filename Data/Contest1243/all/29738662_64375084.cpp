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
    vi v(n);
    fr(n)
    cin>>v[i];
    sort(ALL(v));
    reverse(ALL(v));
    vi sol;
    for(int i=0;i<n;i++)
    {
        sol.pb(min(v[i],i+1));
    }
    cout<<*max_element(ALL(sol))<<endl;
}
int32_t main()
{
    fast;
    ll t=1;cin>>t;
    fr(t)
    solve();
}
