#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//typedef tree < int , null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> TREE;
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define pss pair<short,short>
#define pld pair<long double,long double >
#define ld long double
#define piii  pair<pii,int>
#define vii vector<pair<int,int> >
#define st first
#define nd second
#define pll pair<ll,ll>
#define speed ios::sync_with_stdio(false);cin.tie();cout.tie();
#define M_PI 3.14159265358979323846
//#define int long long
const int mod=1000000007;
//const int mod=998244353;
const int inf=1000000009;
const long long INF=1000000000000000009;
const long long big=1000000000000000;
const long double eps=0.0000000001;
using namespace std;
bool O[100005];
int main()
{
    speed
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    ll a=p%w,b=(-d+d*w)%w;
    ll x=(w-a)%w;
    ll ile=0;
    bool czy=false;
    while((ile*b)%w!=x)
    {
        ll l=(ile*b)%w;
        if(O[l])
        {
            czy=true;
            break;
        }
        O[l]=1;
        ile++;
    }
    ll wins=(p-d*ile)/w;
    ll wynik=ile+wins;
    if(czy||wynik>n||wins<0)
    {
        cout<<-1;
        return 0;
    }
    cout<<wins<<" "<<ile<<" "<<n-wins-ile;
    return 0;
}
