/*
    STARK_BOY
*/
#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repe(i,a,b) for(ll i=a;i<=b;i++)
#define bac(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long ll;
typedef vector< ll > vi;
typedef vector<pair<ll,ll> > vpii;
typedef pair<ll,ll> pii;
#define all(c) c.begin(),c.end()
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setbitc(x) __builtin_popcount(x)
#define init(x,a) memset(x,a,sizeof(x))
#define INF 1000000000  
#define MOD 1000000007
#define MO 1000000006
#define M 998244353
#define PI           3.14159265358979323846  /* pi */
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>; 
ll modExpo(ll x,ll n)
{
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modExpo((x*x)%MOD,n/2);
    else                             //n is odd
        
        return (x*modExpo((x*x)%MOD,(n-1)/2))%MOD;

}
ll modInverse(ll n) 
{ 
    return modExpo(n,MOD-2); 
}
#define N 1000005
//Variables Start   
ll n,m,k,ar[N],br[N];
string s;
//Variables End
ll sub(ll a, ll b){return (a-b+MOD)%MOD;}
ll add(ll a, ll b){return (a+b)%MOD;}
ll mul(ll a, ll b){return (a*b)%MOD;}
int main()
{
    ios
    int ti=1;
    cin>>ti;
    while(ti--)
    {
        ll r1=0,p1=0,s1=0,r2=0,p2=0,s2=0;
        cin>>n>>r1>>p1>>s1;
        cin>>s;
        rep(i,0,n)
        {
            if(s[i]=='R')r2++;
            else if(s[i]=='P')p2++;
            else if(s[i]=='S')s2++;
        }

        ll ans=0;
        ans+=min(r1,s2);
        ans+=min(p1,r2);
        ans+=min(s1,p2);
        ll mid=(n+1)/2;
        if(ans<mid)cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            ll t1=min(r1,s2);
            ll t2=min(p1,r2);
            ll t3=min(s1,p2);
            string temp="",temp2="";
            rep(i,0,r1-t1)temp+='R';
            rep(i,0,p1-t2)temp+='P';
            rep(i,0,s1-t3)temp+='S';
            rep(i,0,n)temp2+='*';
            rep(i,0,n)
            {
                if(s[i]=='S' && t1){temp2[i]='R';t1--;}
                if(s[i]=='R' && t2){temp2[i]='P';t2--;}
                if(s[i]=='P' && t3){temp2[i]='S';t3--;}
            }

            ll j=0;
            rep(i,0,n)if(temp2[i]=='*'){temp2[i]=temp[j];j++;}
            cout<<temp2<<endl;
        }
    }
    return 0;
        
}