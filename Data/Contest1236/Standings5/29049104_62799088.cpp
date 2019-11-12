#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
// #define int ll
using namespace std;
const int INF (1 << 30);
const ll LLINF (1LL << 55LL);
const int MOD = 1000000007;
const int MAX = 510000;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    ll n;
    cin>>n;
    vector<ll> v[400];
    for(int j=1;j<n*n+1;j++){
        ll s=j%(2*n);
        if(s==0) v[0].push_back(j);
        else if(s<=n){
            v[s-1].push_back(j);
        } else{
            v[2*n-s].push_back(j);
        }    
    }
    rep(i,n){
        for(ll j:v[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}