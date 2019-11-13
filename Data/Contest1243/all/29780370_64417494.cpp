#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rep0(a,b) for(int a=0;a<b;a++)
#define rep1(a,b) for(int a=1;a<=b;a++)
#define repp(a,b,c) for(int a=b;a<c;a++)
#define rev(a,b,c) for(int a=b;a>=c;a--)
#define in insert
#define len length()
#define si size()
#define lb lower_bound
#define ub upper_bound
#define beg begin()
#define en end()
#define F first
#define S second
#define pr(a) cout<<a
#define pr2(a,b) cout<<a<<" "<<b<<"\n"
#define get(a) cin>>a
#define nextl cout<<"\n"
#define deb(x) cout<<#x<<"="<<x<<"\n";
const ll mod = 1000000007;
const ll maxn = 500005;
const ll mm = 1e+18;
ll power(ll x, ll y)
{
    ll res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res;
}
ll ncr(ll n, ll k)
{
    ll C[k+1];
    memset(C, 0, sizeof(C));

    C[0] = 1;

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = min(i, k); j > 0; j--)
            C[j] = (C[j] + C[j-1])%mod;
    }
    return C[k];
}
int fii(vector<pair<char,int>>v,char c,int x){
    repp(i,x,v.si){
        if(v[i].F==c&&i!=x) return i;
    }
    return -1;
}
void solve()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    vector<pair<char,int>>v1,v2;
    vector<int>v3;
    rep0(i,n){
        if(s1[i]!=s2[i]){
            v1.pb({s1[i],i+1});
            v2.pb({s2[i],i+1});
            v3.pb(i);
        }
    }
    int a1[26]={0};
    rep0(i,v3.si){
        int x1=(int)(v1[i].F-'a');
        int x2=(int)(v2[i].F-'a');
        a1[x1]++;
        a1[x2]++;
    }
    bool p=false;
    rep0(i,26){
        if(a1[i]%2) p=true;
    }
    if(p) cout<<"No\n";
    else{
        cout<<"Yes\n";
        if(v3.si==0){
            cout<<"1\n";
            cout<<"1 1\n";
        }
        else{
            vector<pair<int,int>>v;
            rep0(i,v3.si){
                //pr2(v1[i].F,v2[i].F);
                if(v1[i].F==v2[i].F) continue;
                else{
                    int x1=fii(v1,v1[i].F,i);
                    //deb(x1);
                    if(x1!=-1){
                        v.pb({v1[x1].S,v2[i].S});
                        swap(v1[x1].F,v2[i].F);
                    }
                    else{
                        int x2=fii(v2,v2[i].F,i);
                        if(x2!=-1){
                        v.pb({v1[i].S,v2[x2].S});
                        swap(v1[i].F,v2[x2].F);
                        }
                        else{
                            int x;
                            repp(j,i,v3.si) {if(v1[i].F!=v2[j].F) {x=j;break;}}
                           // deb(x);
                           v.pb({v1[i].S,v2[x].S});
                           swap(v1[i].F,v2[x].F);
                           i--;
                           continue;
                        }
                    }
                }
            }
            cout<<v.si<<endl;
            for(auto p:v){
                cout<<p.F<<" "<<p.S<<endl;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
        //nextl;
    }
    return 0;
}
