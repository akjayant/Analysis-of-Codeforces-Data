#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define rep(i,n) for(int i=0;i<n;i++)
#define sz(x) ((ll)(x).size())
#define pb push_back
#define mp make_pair
#define bit(n) (1LL<<(n))
#define F first
#define S second
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
const ll INF = 1LL<<60;
const ll mod = 1e9 + 7;

int main() {
    int n,m;
    cin >> n >> m;
    ll cnt=0;
    int dpn[n+1]={};
    int dpm[m+1]={};
    dpn[0]=1;
    dpn[1]=2;
    for(int i=2;i<n;i++){
        dpn[i]=(dpn[i-1]+dpn[i-2])%mod;
    }
    dpm[0]=1;
    dpm[1]=2;
    for(int i=2;i<m;i++){
        dpm[i]=(dpm[i-1]+dpm[i-2])%mod;
    }
    cnt=dpn[n-1]+dpm[m-1]-1;
    cnt=cnt%mod;
    cnt*=2;
    cnt=cnt%mod;
    cout << cnt;

}

/*
1
2
3
5
 */

