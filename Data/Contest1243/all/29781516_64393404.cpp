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
        string s,t;
        cin>>s>>t;
        vector<pll>p(0);
        int i=0;
        while(s!=t&&i<n){
            if(s[i]==t[i]){
                i++;
                continue;
            }else{
                int j=i+1;
                bool f=0;
                REP(k,j,n){
                    if(s[i]==s[k]){
                        f=1;
                        p.pb(mp(k,i));
                        swap(s[k],t[i]);
                        break;
                    }
                }
                if(f){
                    i++;
                    continue;
                }else{
                    j=i+1;
                    REP(k,j,n){
                        if(s[i]==t[k]){
                            p.pb(mp(n-1,k));
                            p.pb(mp(n-1,i));
                            swap(s[n-1],t[k]);
                            swap(s[n-1],t[i]);
                            break;
                        }
                    }
                    i++;
                }
            }
        }
        if(s==t){
            cout<<"Yes"<<'\n';
            cout<<p.size()<<'\n';
            rep(i,p.size()){
                cout<<p[i].first+1<<' '<<p[i].second+1<<'\n';
            }
        }else{
            cout<<"No"<<'\n';
        }
    }
}