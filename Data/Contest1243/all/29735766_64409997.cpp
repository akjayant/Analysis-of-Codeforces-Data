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
        ll n;
        cin>>n;
        string s1;
        string s2;
        cin>>s1>>s2;
        bool flag=0;
        vector<pll> ans;
        for(ll i=0;i<n;i++)
        {
            if(s1[i]==s2[i])
            {
                continue;
            }
            else
            {
                ll in1 = -1;
                ll in2 = -1;
                for(ll j=i+1;j<n;j++)
                {
                    if(s1[i]==s1[j])
                    {
                        in1 = j;
                        break;
                    }
                    else if(s2[j]==s1[i])
                    {
                        in2 = j;
                    }
                }
                if(in1!=-1)
                {
                    ans.pb(mp(in1,i));
                    swap(s1[in1],s2[i]);
                }
                else if(in2!=-1)
                {
                    ans.pb(mp(i,i));
                    swap(s1[i],s2[i]);
                    ans.pb(mp(i,in2));
                    swap(s1[i],s2[in2]);
                }
                else
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
            cout<<ans.size()<<endl;
            for(auto &x:ans)
            {
                cout<<x.fi+1<<' '<<x.se+1<<endl;
            }
        }
    }
    return 0;
}





























