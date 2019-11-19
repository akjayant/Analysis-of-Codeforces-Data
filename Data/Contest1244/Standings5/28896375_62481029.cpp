#include<bits/stdc++.h>
#define ls rt<<1
#define rs rt<<1|1
#define lson rt<<1,l,M
#define rson rt<<1|1,M+1,r
#define PI acos(-1)
#define MM int M=(l+r)>>1;
#define fu(i,r,t) for(int i=r;i<=t;i++)
#define fd(i,r,t) for(int i=r;i>=t;i--)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl '\n'
#define lcm(a,b) (a*b)/__gcd(a,b)
#define Case(i,ans) cout<<"Case "<<i<<": "<<ans<<endl;
#define cp(i,ans) printf("%.if",ans);
#define cpp(i,ans) cout<<setprecision(i)<<fixed<<ans<<endl;
#define ppb pop_back
#define ppf pop_front
#define pb push_back
#define pf push_front
#define pq priority_queue
#define lowbit(x) (x)&(-x)
#define all(V) V.begin(),V.end()
#define ms multiset
#define mod(x) ((x+mo_num)%mo_num)
#define vc vector
#define vct vector<int>
#define fa(i,V) for(auto i:V)
#define out(i) cout<<(i)<<endl;
#define fi first
#define se second
#define fun(i) fu(i,1,n)
#define fut(i) fu(i,1,t)
#define fum(i) fu(i,1,m)
#define ld long double
#define umap unordered_map
#define P pair<int,int>
#define SET set<int>
using namespace std;
const int INF=LLONG_MAX-1e10;
const int maxn=1e6+5;
const int mo_num=1e9+7;
int n,m,a[maxn],b[maxn],ans;
map<P,int>X;
int x,y,fm;
int w,d,p;
bool can(int z)
{
    if((p-n*d+d*z)%fm==0 && (w*n-p-z*w)%fm==0){
        x=(p-n*d+d*z)/fm;
        y=(w*n-p-z*w)/fm;
        if(x+y+z==n && x>=0 && y>=0 && (x*w+y*d)==p)return 1;
    }
    return 0;
}
int32_t main()
{
    IOS
    cin>>n>>p>>w>>d;
    int zuo=n-p/d,you=n-p/w+1;
    fm=w-d;
//    int tox=(p-n*d)%fm,toy=(w*n-p)%fm;
    fu(z,max(zuo,(int)0),min(you,n))
    {
        if(X[{(d*z)%fm,(w*z)%fm}]){
            out(-1)
            return 0;
        }else{
            X[{(d*z)%fm,(w*z)%fm}]=1;
            if(can(z))
            {
                cout<<x<<" "<<y<<" "<<z;
                return 0;
            }
        }
    }
    out(-1)
    return 0;
}
