//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itmin(x,y) (x) = min((x),(y));
#define itmax(x,y) (x) = max((x),(y));
#define cotu cout
#define itn int
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF = 1e9 + 7;

void solve(){
    ll n; cin>>n;
    bool prime = true;
    bool two = true;
    bool thre = true;
    vector<ll> v;
    for(ll i = 2; i*i <= n; i++){
        if(n%i==0){
            v.pb(i);
            if(i*i!=n) v.pb(n/i);
            //if(i%2==1) two = false;
            //if(i%3!=0) thre = false;
            //prime = false;
        }
    }
    sort(all(v));
    if(v.size()==0) cout<<n;
    else{
        int j = v[0];
        bool t = true;
        for(int i = 1; i < v.size(); i++){
            if(v[i]%j!=0){
                cout<<1;
                return;
            }
        }
        cout<<j;
    }

}

int main(){
    int t = 1;
    //cin>>t;
    while(t--) solve();
}