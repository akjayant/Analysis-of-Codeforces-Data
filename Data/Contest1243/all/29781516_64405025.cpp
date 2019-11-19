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
std::vector<bool> IsPrime;
void sieve(size_t max){
    if(max+1 > IsPrime.size()){     // resizeで要素数が減らないように
        IsPrime.resize(max+1,true); // IsPrimeに必要な要素数を確保
    } 
    IsPrime[0] = false; // 0は素数ではない
    IsPrime[1] = false; // 1は素数ではない

    for(size_t i=2; i*i<=max; ++i) // 0からsqrt(max)まで調べる
        if(IsPrime[i]) // iが素数ならば
            for(size_t j=2; i*j<=max; ++j) // (max以下の)iの倍数は
                IsPrime[i*j] = false;      // 素数ではない
}
int main(){
    ll n;cin>>n;
    sieve(1000010);
    vector<ll>div(0);
    ll k=n;
    rep(i,sqrt(k)+1){
        if(IsPrime[i]){
            if(n%i==0)div.pb(i);
            while(n%i==0)n/=i;
        }
    }
    if(n!=1)div.pb(n);
    if(div.size()>1)cout<<1<<endl;
    else if(div.size()==1)cout<<div[0]<<endl;
    else cout<<n<<endl;
}