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

int32_t main()
{
    IOS
    int t;
    cin>>t;
    fut(p)
    {
        cin>>n;
        string k;
        cin>>k;
        int key=0;
        int xia=INF;
        fu(i,1,k.length())
        {
            if(k[i-1]=='1') {
                key++;
                xia=min({xia,n-i,i-1});
            }
        }
        if(!key)
        {
            out(n)
        }else{
            out(max(n+key,2*n-2*xia))
        }
    }
    return 0;
}
