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

vi g[100000];
vvi c(4,vi(100000,0));

vi color(100000,0);
void dfs(int s, int p){
    fr(i,g[s]){
        if(i!=p){
            color[i]=color[s]%3+1;
            dfs(i,s);
        }
    }
}
vi ed(100000,0);
int main() {
    //clock_t tm = clock();
    fastio;
    ll n,x,y;string s;
    cin>>n;
    f(i,1,4)f(j,0,n)cin>>c[i][j];
    f(i,0,n-1){
        cin>>x>>y;
        g[x-1].pb(y-1);g[y-1].pb(x-1);ed[x-1]++;ed[y-1]++;
    }
    int source=0;
    f(i,0,n){
        if(ed[i]==1)source=i;
        if(ed[i]>2){
            cout<<-1<<endl;
            return 0;
        }
    }
    color[source]=1;
    dfs(source,-1);
    s="123";
    ll ans=0;
    f(i,0,n){ans += c[color[i]][i];
    }
    ll tmp=0;
    f(i,0,n){
        if(color[i]==2){
            tmp += c[3][i];
        }
        if(color[i]==3){
            tmp += c[2][i];
        }
        if(color[i]==1){
            tmp += c[1][i];
        }
    }
    if(tmp<ans){
        ans=tmp;s="132";
    }
    tmp=0;
    f(i,0,n){
        if(color[i]==2){
            tmp += c[3][i];
        }
        if(color[i]==3){
            tmp += c[1][i];
        }
        if(color[i]==1){
            tmp += c[2][i];
        }
    }
    if(tmp<ans){
        ans=tmp;s="231";
    }
    tmp=0;
    f(i,0,n){
        if(color[i]==2){
            tmp += c[1][i];
        }
        if(color[i]==3){
            tmp += c[3][i];
        }
        if(color[i]==1){
            tmp += c[2][i];
        }
    }
    if(tmp<ans){
        ans=tmp;s="213";
    }
    tmp=0;
    f(i,0,n){
        if(color[i]==2){
            tmp += c[1][i];
        }
        if(color[i]==3){
            tmp += c[2][i];
        }
        if(color[i]==1){
            tmp += c[3][i];
        }
    }
    if(tmp<ans){
        ans=tmp;s="312";
    }
    tmp=0;
    f(i,0,n){
        if(color[i]==2){
            tmp += c[2][i];
        }
        if(color[i]==3){
            tmp += c[1][i];
        }
        if(color[i]==1){
            tmp += c[3][i];
        }
    }
    if(tmp<ans){
        ans=tmp;s="321";
    }
    cout<<ans<<endl;
    f(i,0,n){
        cout<<s[color[i]-1]<<" ";
    }
    cout<<endl;
    //cout<<((clock()-tm)*1.0)/CLOCKS_PER_SEC<<endl;
}