// https://codeforces.com/profile/_Mr_Fab
// Because there was a same question before
 #include<bits/stdc++.h>
    using namespace std;
  
    static int LOCAL=0;
 
    #define F0(a) memset(a,0,sizeof(a));
    #define print(v,i,x) for(int j=i;j<=x;j++){cout<<v[j]<<" ";}cout<<endl;
    #define pb push_back
    #define mp make_pair
    #define lli long long int
    #define ulli unsigned long long int
    #define all(x) x.begin(),x.end()
    #define sz(x) ((int)x.size())
    #define f first
    #define s second
 
    #define si(x) scanf("%d",&x)
    #define slli(x) scanf("%lld",&x)
    #define si2(x,y) scanf("%d %d",&x,&y)
    #define si3(x,y,z) scanf("%d %d %d",&x,&y,&z)
    #define slli2(x,y) scanf("%lld %lld",&x,&y)
    #define slli3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z)
 
    #define pi(x) printf("%d",x)
    #define pi2(x,y) printf("%d %d",x,y)
    #define pi3(x,y,z) printf("%d %d %d",x,y,z)
    #define plli(x) printf("%lld",x)
    #define plli2(x,y) printf("%lld %lld",x,y)
    #define plli3(x,y,z) printf("%lld %lld %lld",x,y,z)
    #define pn printf("\n")
    #define ps printf(" ")
    #define pc(c) printf("%c",c)
 
    #define FOR(i,x,n) for(int i=x;i<=n;i++)
    #define ROF(i,x,n) for(int i=x;i>=n;i--)
    #define fr(i,x,n) for(int i=x;i<n;i++)
 
    #define debug(x) cout << "  - " << #x << ": " << x << endl;
    #define debugs(x, y) cout << "  - " << #x << ": " << x << "         " << #y << ": " << y << endl;
    #define debugss(x, y, z) cout << "  - " << #x << ": " << x << "         " << #y << ": " << y << "         " << #z << ": " << z <<  endl;
    #define fastIO  std::ios::sync_with_stdio(false);cin.tie(NULL);
    #define cut cout<<"------------------------------------------\n";
    #define cut1 cout<<"******************************************\n";
 
    typedef vector<int> vi;
    typedef vector<lli> vlli;
    typedef vector<pair<int,int>> vii;
 
    typedef pair<int,int> prii;
    typedef pair<int,lli> prilli;
    typedef pair<lli,int> prllii;
    typedef pair<lli,lli> prllilli;
 
    const lli mod = 1000000007ll;
    const lli MOD = 1000000009ll;
    const lli INF = LLONG_MAX/10;
    const int inf = INT_MAX/10;
 
    lli powermod(lli _a,lli _b,lli _m=mod){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a)%_m;_b/=2;_a=(_a*_a)%_m;}return _r;}
    lli power(lli _a,lli _b){lli _r=1;while(_b){if(_b%2==1)_r=(_r*_a);_b/=2;_a=(_a*_a);}return _r;}
    lli add(lli a,lli b,lli m=mod){lli x=a+b;while(x>=m)x-=m;return x;}
    lli sub(lli a,lli b,lli m=mod){lli x=a-b;while(x<0)x+=m;return x;}
    lli mul(lli a,lli b,lli m=mod){return ((a%m)*(b%m))%m;}
    lli gcd(lli a,lli b){while(a&&b)a>b?a%=b:b%=a;return a+b;}
    lli lcm(lli a,lli b){return (max(a,b)/gcd(a,b))*min(a,b);}
 
    struct pair_hash {
        std::size_t operator () (const std::pair<int,int> &p) const {
            auto h1 = std::hash<lli>{}(p.first);
            auto h2 = std::hash<lli>{}(p.second);
            return (int)add(h1,mul(h2,h1,MOD));
        }
    };
 
    struct cmp{
        bool operator()(pair<int,prllilli> const & l,pair<int,prllilli> const & r){
            return l.s.f<r.s.f;
        }
    }myobject;
 
    const int N=200010;
    set<int> adj[N];
    set<int> vis; 
    vi ans;
    int s=0,n,m; 
 
    void dfs(int u){
        s++;
        int last=0;
     
        vi v;
 
        for(auto it=adj[u].begin();it!=adj[u].end();it++){
            auto jt=vis.upper_bound(-(*it));
            while(jt!=vis.end() && abs(*jt)>last){
                if(adj[u].find(abs(*jt))==adj[u].end()){
                    int tmp=abs(*jt);
                    jt=vis.erase(jt);
                    //dfs(tmp);
                    v.pb(tmp);
                }
                else
                    break;
            }
            last=*it;
        }
 
        for(int x:v)
            dfs(x);
 
    }
 
    int main(){
 
    
        si2(n,m);
 
        int x,y;
        FOR(i,1,m){
            si2(x,y);
            adj[x].insert(y);
            adj[y].insert(x);
        }
 
        FOR(i,1,n)vis.insert(-i),adj[i].insert(n+1);
 
        FOR(i,1,n){
            if(vis.find(-i)!=vis.end()){
                s=0;
                vis.erase(-i);
                dfs(i);
                ans.pb(s);
            }
        }
 
        sort(all(ans));
 
        pi(sz(ans)-1);
 
        return 0;
    }