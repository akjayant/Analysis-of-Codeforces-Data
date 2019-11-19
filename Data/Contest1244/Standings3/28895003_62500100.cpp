#include<bits/stdc++.h>
using namespace std;
#define MOD           998244853
#define C             1000000007
#define pi            acos(-1)
#define int           long long 
#define D             double
#define S             second
#define F             first
#define pb            push_back
#define ff            fflush(stdout)
#define ppb           pop_back
#define B(c)          (c).begin()
#define E(c)          (c).end()
#define all(c)        (c).begin(),(c).end()
#define rall(c)       (c).rbegin(),(c).rend()
#define SORT(v)       sort(ALL(v))  
#define lb            lower_bound
#define ub            upper_bound
#define si(c)         (int)((c).size())
#define L(c)           si(c)-1
#define gcd(a,b)      __gcd(a,b)
#define lcm(a,b)      (a*(b/gcd(a,b)))
#define sqr(a)        ((a) * (a))
#define optimize()    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define accuracy      cout << fixed << setprecision(18);
#define inf           (int)2e18
#define pow(i,n)      (int)pow((int)i,n)
typedef vector<int>                           vi;
typedef pair<int,int>                         pii;
typedef pair<int,pii>                         pipii;
typedef vector<vector<int> >                  vvi;
typedef map<int,int>                          mp;
typedef map<string,int>                       msi;
typedef priority_queue<pii, vector<pii>, greater<pii> > pq;
inline  bool checkBit(int n, int i) { return n&((int)1<<i); }
inline  int setBit(int n, int i) { return n|((int)1<<i);; }
inline  int resetBit(int n, int i) { return n&(~((int)1<<i)); }
inline  bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }
inline  bool isLeapYear(int year) { return (year%400==0) || (year%4==0 && year%100!=0); }
inline  void normal(int &a) { a = (a+MOD)%MOD; }
inline  int modMul(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline  int modAdd(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline  int modSub(int a, int b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline  int modPow(int b, int p) { int r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline  int modInv(int a) { return modPow(a, MOD-2); }
inline  int modDiv(int a,int b) { return modMul(a, modInv(b)); }
inline  int fact(int r){ int ans=1;while(r)ans=modMul(ans,r),r--;return ans; }
inline  int invfact(int r){int ans=1;while(r)ans=modMul(ans,modInv(r)),r--; return ans;}
inline  D dgcd(D a,D b){ if(a<b)return dgcd(b,a); if(b<.0001)return a; return dgcd(b,fmod(a,b));}


const int N=1e5+1;
int a[N],n,k,diff,mx,ans,sum;

int check1(int mn){
     mx=mn+diff;
     sum=0;
     for(int i=0;i<n;i++){
          if(a[i]>=mn&&a[i]<=mx)continue;
          sum+=min(abs(a[i]-mn),abs(a[i]-mx));
     }
     return sum;
}
bool check(){
     int s=0,e=1e9-diff;
     while(s<=e){
          int mid=(s+e)/2;
          int  fl1=check1(mid),fl2=check1(mid+1);
          if(fl1<=k||fl2<=k){
              return 1; 
          }
          else if(fl1>fl2)s=mid+1;
          else e=mid-1;
     }
     return 0;
}
void solve(){
     cin>>n>>k;
     for(int i=0;i<n;i++){
          cin>>a[i];
     }
     int s=0,e=1e9;
     while(s<=e){
          diff=(s+e)/2;
          if(check())
          e=diff-1,ans=diff;
          else s=diff+1;
     }
     cout<<ans<<endl;
}
 
signed main(){   
    optimize();       
    int t=1;
    //accuracy;
    //freopen("input.txt", "r", stdin);
    //cin>>t;
    while(t--){
        solve();
    }
}
