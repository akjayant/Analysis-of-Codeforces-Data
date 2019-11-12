#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pii             pair<int , int >
#define in(a)           scanf("%d", &a)
#define in2(a, b)       scanf("%d%d", &a, &b)
#define in3(a, b, c)    scanf("%d%d%d", &a, &b, &c)
#define piil            pair<ll , ll >
#define inl(a)          scanf("%lld", &a)
#define inl2(a, b)      scanf("%lld%lld", &a, &b)
#define inl3(a, b, c)   scanf("%lld%lld%lld", &a, &b, &c)
#define ins(s)          scanf("%s",s)
#define prst(s)         printf("%s\n",s)
#define pn              printf("\n")
#define pr(a)           printf("%d\n", a)
#define prl(a)          printf("%lld\n", a)
#define prs(a)          printf("%d ", a)
#define pr2(a, b)       printf("%d %d\n", a, b)
#define pr3(a, b, c)    printf("%d %d %d\n", a, b, c)
#define prsl(a)         printf("%lld ", a)
#define prl2(a, b)      printf("%lld %lld\n", a, b)
#define prl3(a, b, c)   printf("%lld %lld %lld\n", a, b, c)
#define pcs(a)          printf("Case %d: ", a)
#define pf              printf
#define sc              scanf
#define m_p             make_pair
#define vi              vector<int >
#define vil             vector<ll >
#define pb              push_back
#define fi              first
#define sc              second
#define mem(a, b)       memset((a), (b), sizeof(a))
#define lg2(n)         (31-__builtin_clz(n))
#define PI		        acos(-1.0)
#define N 2000010
#define unq(v)       v.erase(unique(all(v)),v.end())
#define inf 2e18
#define ll long long
#define ull unsigned long long
#define fbo find_by_order
#define ook order_of_key
#define fi first
#define sc second
#define __  std::ios_base::sync_with_stdio (false); cin.tie(0); cout.tie(0);
#define Check(n, pos) (n & (1<<pos))
#define Set(n, pos) (n | (1<<pos))
ll gcd(ll a, ll b){if(b==0) {return a;}return gcd(b, a % b);}
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename F, typename S>
using ordered_map = tree<F, S, less<F>, rb_tree_tag, tree_order_statistics_node_update>;
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); deb(_it, args); }
void deb(istream_iterator<string> it) {}
template<typename T, typename... Args>
void deb(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    deb(++it, args...);
}
ll BigMod(ll B,ll P,ll M){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}
//______________________________________________________________________________________________________________________________________________________
ll dp[N],arr[N];
char str[N];
int main()
{
    __;
   ll n,m,k,a,b,t;
   ll sum=0;
   string s;
   cin>>t;
   while(t--)
   {
       cin>>n;
       for(int i=0;i<n;i++) cin>>arr[i];
       sort(arr,arr+n);
       int ans=1;
       for(int i=1;i<=n;i++)
       {
           int cn=0;
           for(int j=0;j<n;j++)
           {
               if(arr[j]>=i)
               {
                   cn++;
               }
           }
           //cout<<i<<" "<<cn<<endl;
           if(cn>=i)
           {
               ans=i;
           }
       }
       cout<<ans<<endl;

   }


    return 0;
}

