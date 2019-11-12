#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
ll a[1010][1010];
ll cnt[1010][1010];
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
int main(){
    ll k;cin>>k;
    while(k){
        k--;
        ll n;cin>>n;
        string s,t;cin>>s>>t;
        vector<ll>a(0);
        rep(i,n){
            if(s[i]!=t[i])a.pb(i);
        }
        bool f=0;
        if(a.size()==0)f=1;
        if(a.size()==2){
            if(s[a[0]]==s[a[1]]&&t[a[0]]==t[a[1]])f=1;
        }
        cout<<(f?"Yes":"No")<<'\n';
    }
}