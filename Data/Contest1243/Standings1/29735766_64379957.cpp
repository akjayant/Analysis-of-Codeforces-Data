/// Code By t_bone_289 (Tushar Singh)
/// An Immature Programmer.... I'm still developing !!
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define endl '\n'
#define M 1000000007
#define error(x) cout << #x << " = " << x << endl;
#define pi 3.14159265358979323846
typedef long long ll;
typedef long double ld;
template <typename T>
void ContainerError(T &v){cout<<"{";for(auto &x:v){cout<<x<<',';}cout<<"}"<<endl;return;}
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll powmod(ll base,ll exp,ll MOD){ll res=1;while(exp>0){if(exp%2==1) res=(res*base)%MOD;base=(base*base)%MOD;exp/=2;}return (res%MOD);}
ll mpow(ll base,ll exp){ll res=1;while(exp>0){if(exp%2==1) res=(res*base);base=(base*base);exp/=2;}return (res);}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        ll n;
        cin>>n;
        cin>>s1>>s2;
        //ll n = s1.size();
        vector<ll> vv;
        for(ll i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                vv.pb(i);
            }
        }
        ll cc = vv.size();
        if(cc!=2)
        {
            cout<<"No"<<endl;
        }
        else
        {
            ll x = vv[0];
            ll y = vv[1];
            if(s1[x]==s1[y] && s2[x]==s2[y])
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
//        ContainerError(v1);
//        ContainerError(v2);

//        error(cc);
//        if(cc!=2)
//        {
//            cout<<"No"<<endl;
//        }
//        else
//        {
//            ll a = v1[vv[0]];
//            ll b = v2[vv[1]];
////            error(a);
////            error(b);
//            if(a==b)
//            {
//                cout<<"Yes"<<endl;
//            }
//            else
//            {
//                cout<<"No"<<endl;
//            }
//
//        }
    }
    return 0;
}





























