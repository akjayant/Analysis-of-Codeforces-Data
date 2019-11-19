#include<bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
typedef long long ll;
typedef long double ld;
#define war(i,s,n) for(long long i=s;i<n;i++)
#define pb push_back
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL)
#define fr first
#define sc second
#define mod 1000000007
#define vctr2d vector<vector<long long>>
#define vctr vector<long long>
#define pll pair<long long,long long>
#define rz(n) resize(n)
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mod2  998244353
#define small -1000000000000000000
#define big 1000000000000000000
#define arrin(a,n) for(int i = 0; i < n ; i++){cin>>a[i];}
#define arrout(a,n) for(int i = 0;i < n; i++){cout<<a[i]<<" ";}
#define ex(s) cout<<s<<endl;exit(0);
#define itr iterator
#define tra(it,m) for(it=m.begin();it!=m.end();++it)
//__________________________________________________________________________________________________________________________________________________________
set<ll> factorize(ll n) {
    set<ll> res;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.insert(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.insert(n);
    }
    return res;
}
int main()
{
          ll n;
          cin>>n;
          set<ll> s = factorize(n);
          if(s.size() != 1){
                    cout<<1<<endl;
                    return 0;
          }
          set<ll> :: itr it = s.begin();
          cout<<*it<<endl;
}
