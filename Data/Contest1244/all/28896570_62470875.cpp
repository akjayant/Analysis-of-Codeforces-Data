#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string>vst;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef map<int,int> dct;


#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define all(ct) ct.begin() , ct.end()
#define endl "\n"
#define fr(i,a) for(auto i:a)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define in(d,v) d.find(v)!=d.end()
#define mp make_pair

bool compare(pll a, pll b)
{   return (a.first*b.second) < (a.second*b.first);
}

const int mod = 1e9 + 7;
const ll inf = ll(1e18);

int main() {
    //clock_t tm = clock();
    fastio;
    ll t,n,x,y;string s;
    cin>>t;
    while(t--){
        cin>>n;cin>>s;
        x=-1;y=-1;
        ll ans = n;
        f(i,0,n){
            if(s[i]=='1'){
                ans++;
                if(x==-1)x=i,y=i;
                else y=i;
            }
        }
        if(x>-1) {
            ans = max(ans, 2 * (n - x));
            ans = max(ans, 2*(y+1));
        }
        cout<<ans<<endl;
    }
    //cout<<((clock()-tm)*1.0)/CLOCKS_PER_SEC<<endl;
}