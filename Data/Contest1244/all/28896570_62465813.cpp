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
    ll t,a,b,c,d,k;string s;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>k;
        int flag=-1;
        f(i,0,k+1){
            int j=k-i;
            if(i*c>=a and j*d>=b){
                flag=1;
                cout<<i<<" "<<j<<endl;
                break;
            }
        }
        if(flag==-1)cout<<flag<<endl;
    }
    //cout<<((clock()-tm)*1.0)/CLOCKS_PER_SEC<<endl;
}